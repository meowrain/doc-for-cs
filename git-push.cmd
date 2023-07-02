@echo off
echo 正在执行git pull,执行仓库更新操作...
git pull

echo 正在执行git add...
git add .

echo 请输入提交信息:
set /p commitMsg=

echo 正在执行git commit...
git commit -m "%commitMsg%"

echo 正在执行git push...
git push -u origin main

echo 执行完成，请到github进行pr操作。
pause