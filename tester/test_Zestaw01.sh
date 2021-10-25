#!/usr/bin/env bash

Zestaw=Zestaw01
Files="Stack:TestStack:stackqueue ONP:TestRPN:onp"

clear
echo -e "\033[95m[[ ${Zestaw} ]]\033[m"

if ! make --no-print-directory -C ${Zestaw}; then
	echo -e "\n\033[93mBuild \033[31mfailure\033[m"
	exit
fi
echo -e "\n\033[93mBuild \033[32msuccess\033[m"

for Triple in ${Files}; do
	Name=${Triple%%:*}
	if test -x ${Zestaw}/${Name}.x; then
		echo -e "\033[93mExecutable '${Name}.x' \033[32mfound\033[m"
	else
		echo -e "\033[93mExecutable '${Name}.x' \033[31mnot found\033[m"
	fi
done
echo ""

for Triple in ${Files}; do
	Name=${Triple%%:*}
	Rest=${Triple#*:}
	Test=${Rest%:*}
	Data=${Rest#*:}

	if test -x ${Zestaw}/${Name}.x; then
		lua tester.luac "${Test}" "${Zestaw}/${Name}.x" "sets/${Data}/*.set"
	fi
done
