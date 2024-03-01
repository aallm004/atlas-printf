#!/bin/bash
#echo -e "#!/usr/bin/env bash\n# $3" > $2
#chmod 755 $2
echo -e "\n>>> git add --all <<<\n"
git add --all
#chmod u+x $1

if ["$1" == ""]; then
	echo -n "Commit Message: "
	read
	# next line needed for windows
	# git update-index --chmod=+x $2
	echo -e "\n>>>  git commit -m \"$REPLY\" <<<\n"
	git commit -m "$REPLY"
fi
if [ "$1"!="" ]; then
	echo -e "\n>>> git commit -m \"$1\" <<<\n"
	git commit -m "$1"
fi

echo -e "\n>>> git push <<<\n"
git push
echo ""
