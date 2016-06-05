#!/bin/sh
git status
sleep 1
git add *
sleep 1
git commit -m "sth"
sleep 1
git push origin master
