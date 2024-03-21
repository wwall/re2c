root_dir=$(pwd)

for f in $(find -name '*.re'); do
    cd $(dirname $f)

    pyfile="$(basename ${f%.re}.py)"
    pytest="example.rs"

    cat "$pyfile" \
        | egrep -v 'warning: rule .*matches empty string \[-Wmatch-empty-string\]' \
        | egrep -v 'warning: tag .* degree of nondeterminism \[-Wnondeterministic-tags\]' \
        > "$pytest"

    # If the autogenerated message appears more than once in the file, then
    # it must have autogenerated header appended at the end. Cut it off.
    msg='Generated by re2c'
    if [ $(grep -c "$msg" "$pytest") -gt 1 ]; then
        # Get the line of the second message occurrence.
        l=$(grep -n "$msg" "$pytest" | tail -n +2 | cut -d : -f 1)
        # Cut off everything past that line.
        head -n $l "$pytest" > "$pytest".mod && mv "$pytest".mod "$pytest"
    fi

    echo "$f"
    python "$pytest" || { echo "*** error ***"; exit 1; }

    rm -f "$pytest"
    cd $root_dir
done

find -name __pycache__ | xargs rm -r

echo "All good."
