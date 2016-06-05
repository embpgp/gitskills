#!/bin/sh

commit(){
	git status
	sleep 1
	git add *
	sleep 1
	git commit -m "sth"
	sleep 1
	git push origin master
	echo "成功提交"
}

commit
