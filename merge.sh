git checkout master
git pull 
git checkout main
git merge master
sh dockerBuild.sh
git add .
git commit -am "auto merge and build"
git push