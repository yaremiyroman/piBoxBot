# place this aliases either in ~/.bash_profile or ~/.bashrc
# for OS X and Raspbian corresponding

alias cc='clear'
alias pi='ssh pi@pi.local'
alias pi_photos='scp -r pi@pi.local:/home/pi/Pictures/cam/ /Users/rom/Documents/'

alias offf='sudo shutdown -h now'
alias bot='python3 piBoxBot/py/bot.py'



alias cc='clear'

alias pi='ssh pi@piMedia.local'
alias pi_rsync_photos='rsync -avz --remove-source-files pi@piMedia.local:/home/pi/Pictures/cam/ /Users/rom/Pictures/cam_synced/'

alias g='git'

alias master='git pull origin master'
alias m='git pull origin master'

alias dev='git pull origin dev'
alias d='git pull origin dev'

alias nnn='npm start'
