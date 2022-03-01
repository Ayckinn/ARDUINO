#!/bin/bash
clear

export LC_ALL=C
echo ""
echo "              +=============================+"
echo "              |         SPYSIA  v1.0        |"
echo "              +===+=====================+===+"
echo "                  |  (c)2022 - Ayckinn  |"
echo "                  +---------------------+"      
echo ""
echo "    +-------------------------------------------------+"
echo "    |              </GENERAL INFORMATION>             |"
echo "    +-------------------------------------------------+"
echo "       >>   Operating System | $(hostnamectl | head -n6 | cut -d " " -f3-4 | tail -n +6)";
#echo "       >>   Operating System | $(hostnamectl | head -n6 | cut -d " " -f5-7 | tail -n +6)"; 
echo "       >>     Kernel version | $(uname -r)";
echo ""
echo "       >>           Hostname | $(hostnamectl | head -1 | cut -d " " -f4)";
echo "       >>           Local IP | $(hostname -I | cut -d " " -f1)";
echo "       >>          Public IP | $(wget http://ipecho.net/plain -O - -q; echo)";
echo ""
echo "       >>        Last update | $(ls -lt --time-style="long-iso" /var/log/apt | grep -o '\([0-9]\{2,4\}[- ]\)\{3\}[0-9]\{2\}:[0-9]\{2\}' -m 1
)";
if [ -x /usr/lib/update-notifier/apt-check ] 
	then echo "       >>   Available update | $(/usr/lib/update-notifier/apt-check --human-readable | head -n1 | cut -d " " -f1)";
	else echo "       >>   Available update | Not installed - sudo apt install update-notifier";
fi

echo ""
echo "       If updates are available, please type the following command to see the list :" 
echo "         >> /usr/lib/update-notifier/apt-check -p"
echo ""

echo "    +-------------------------------------------------+"
echo "    |          </SYSTEM'S INSTALLED COMMANDS>         |"
echo "    +-------------------------------------------------+"
if [ -x /usr/bin/apt ] 
	then echo "       >>                apt | $(apt -v             | cut -d " " -f2)";
	else echo "       >>                apt | Not installed";
fi
if [ -x /usr/bin/aptitude ] 
	then echo "       >>           aptitude | $(aptitude --version | head -n1 | cut -d " " -f2)";
	else echo "       >>           aptitude | Not installed - sudo apt install aptitude";
fi
if [ -x /usr/bin/ld ] 
	then echo "       >>           binutils | $(ld --version       | head -n1 | cut -d " " -f7-7)";
	else echo "       >>           binutils | Not installed - sudo apt install binutils";
fi
if [ -x /usr/bin/bison ] 
	then echo "       >>              bison | $(bison --version    | head -n1 | cut -d " " -f4)";
	else echo "       >>              bison | Not installed - sudo apt install bison";
fi
if [ -x /usr/bin/bzip2 ] 
	then echo "       >>              bzip2 | $(bzip2 --version 2>&1 < /dev/null | head -n1 | cut -c 50-54)";
	else echo "       >>              bzip2 | Not installed - sudo apt install bzip2";
fi
if [ -x /usr/bin/chown ] 
	then echo "       >>          coreutils | $(chown --version    | head -n1 | cut -d " " -f4)";
	else echo "       >>          coreutils | Not installed";
fi
if [ -x /usr/bin/curl ] 
	then echo "       >>               curl | $(curl --version     | head -n1 | cut -d " " -f2)";
	else echo "       >>               curl | Not installed - sudo apt install curl";
fi
if [ -x /usr/bin/dfc ] 
	then echo "       >>                dfc | $(dfc -v             | cut -d " " -f2)";
	else echo "       >>                dfc | Not installed - sudo apt install dfc";
fi
if [ -x /usr/bin/diff ] 
	then echo "       >>               diff | $(diff --version     | head -n1 | cut -d " " -f4)";
	else echo "       >>               diff | Not installed - sudo apt install diff";
fi
if [ -x /usr/bin/exa ] 
	then echo "       >>                exa | $(exa --version      | head -n2 | cut -c 2-8 | tail +2)";
	else echo "       >>                exa | Not installed - sudo apt install exa";
fi
if [ -x /usr/sbin/fdisk ] 
	then echo "       >>              fdisk | $(fdisk --version    | cut -d " " -f4)";
	else echo "       >>              fdisk | Not installed - sudo apt install fdisk";
fi
if [ -x /usr/bin/find ] 
	then echo "       >>               find | $(find --version     | head -n1 | cut -d " " -f4)";
	else echo "       >>               find | Not installed - sudo apt install find";
fi
if [ -x /usr/bin/g++ ] 
	then echo "       >>                g++ | $(g++ --version      | head -n1 | cut -d " " -f4)";
	else echo "       >>                g++ | Not installed - sudo apt install g++";
fi
if [ -x /usr/bin/gawk ] 
	then echo "       >>               gawk | $(gawk --version | head -n1 | cut -c 9-13)";
	else echo "       >>               gawk | Not installed - sudo apt install gawk";
fi
if [ -x /usr/bin/gcc ] 
	then echo "       >>                gcc | $(gcc --version      | head -n1 | cut -d " " -f4)";
	else echo "       >>                gcc | Not installed - g++ tools";
fi
if [ -x /usr/bin/git ] 
	then echo "       >>                git | $(git --version      | cut -d " " -f3)";
	else echo "       >>                git | Not installed - sudo apt install git";
fi
if [ -x /usr/bin/grep ] 
	then echo "       >>               grep | $(grep --version     | head -n1 | cut -d " " -f4)";
	else echo "       >>               grep | Not installed - sudo apt install grep";
fi
if [ -x /usr/bin/gzip ] 
	then echo "       >>               gzip | $(gzip --version     | head -n1 | cut -d " " -f2)";
	else echo "       >>               gzip | Not installed - sudo apt install gzip";
fi
if [ -x /usr/bin/inxi ] 
	then echo "       >>               inxi | $(inxi --version     | head -n1 | cut -d " " -f2)";
	else echo "       >>               inxi | Not installed - sudo apt install inxi";
fi
if [ -x /usr/bin/ldd ] 
	then echo "       >>                ldd | $(ldd --version      | head -n1 | cut -d " " -f5)";
	else echo "       >>                ldd | Not installed - sudo apt install ldd";
fi
if [ -x /usr/bin/m4 ] 
	then echo "       >>                 m4 | $(m4 --version       | head -n1 | cut -d " " -f4)";
	else echo "       >>                 m4 | Not installed - sudo apt install m4";
fi
if [ -x /usr/bin/make ] 
	then echo "       >>               make | $(make --version     | head -n1 | cut -d " " -f3)";
	else echo "       >>               make | Not installed - sudo apt install make";
fi
if [ -x /usr/bin/makeinfo ] 
	then echo "       >>           makeinfo | $(makeinfo --version | head -n1 | cut -d " " -f4)";
	else echo "       >>           makeinfo | Not installed - sudo apt install texinfo";
fi
if [ -x /usr/bin/patch ] 
	then echo "       >>              patch | $(patch --version    | head -n1 | cut -d " " -f3)";
	else echo "       >>              patch | Not installed - sudo apt install patch";
fi
if [ -x /usr/bin/perl ] 
	then echo "       >>               perl | $(perl --version | head -n2 | cut -c 44-49 |tail +2)";
	else echo "       >>               perl | Not installed - sudo apt install perl";
fi
if [ -x /usr/bin/python3 ] 
	then echo "       >>            python3 | $(python3 --version  | head -n1 | cut -d " " -f2)";
	else echo "       >>            python3 | Not installed - sudo apt install python3";
fi
if [ -x /usr/bin/sed ] 
	then echo "       >>                sed | $(sed --version      | head -n1 | cut -d " " -f4)";
	else echo "       >>                sed | Not installed - sudo apt install sed";
fi
if [ -x /usr/bin/snap ] 
	then echo "       >>               snap | $(snap --version | head -n1 | cut -c 9-20)";
	else echo "       >>               snap | Not installed - sudo apt install snapd";
fi
if [ -x /usr/bin/sudo ] 
	then echo "       >>               sudo | $(sudo --version     | head -n1 | cut -d " " -f3)";
	else echo "       >>               sudo | Not installed - sudo apt install sudo";
fi
if [ -x /usr/bin/tar ] 
	then echo "       >>                tar | $(tar --version      | head -n1 | cut -d " " -f4)";
	else echo "       >>                tar | Not installed - sudo apt install tar";
fi
if [ -x /usr/bin/uptime ] 
	then echo "       >>             uptime | $(uptime --version   | head -n1 | cut -d " " -f4)";
	else echo "       >>             uptime | Not installed - sudo apt install uptime";
fi
if [ -x /usr/bin/wget ] 
	then echo "       >>               wget | $(wget --version     | head -n1 | cut -c 10-14)";
	else echo "       >>               wget | Not installed - sudo apt install wget";
fi
if [ -x /usr/bin/xz ] 
	then echo "       >>                 xz | $(xz --version       | head -n1 | cut -d " " -f4)";
	else echo "       >>                 xz | Not installed - sudo apt install xz";
fi
if [ -x /usr/bin/zsh ] 
	then echo "       >>                zsh | $(zsh --version       | cut -d " " -f2)";
	else echo "       >>                zsh | Not installed - sudo apt install zsh";
fi
echo "    +-------------------------------------------------+"
echo "    |       </$(whoami | tr '[:lower:]' '[:upper:]')'S INSTALLED CLI PROGRAMS>       |"
echo "    +-------------------------------------------------+"
if [ -x /usr/bin/glances ] 
	then echo "       >>            glances | $(glances --version  | head -n1 | cut -c 29-33)";
	else echo "       >>            glances | Not installed - sudo apt install glances";
fi
if [ -x /usr/bin/mc ]
	then echo "       >>                 mc | $(mc --version       | head -n1 | cut -d " " -f4-4)";
	else echo "       >>                 mc | Not installed - sudo apt install mc";
fi
if [ -x /usr/bin/mplayer ] 
	then echo "       >>            mplayer | $(mplayer -v         | head -n1 | cut -d " " -f2)";
	else echo "       >>            mplayer | Not installed - sudo apt install mplayer";
fi
if [ -x /usr/bin/nano ] 
	then echo "       >>               nano | $(nano --version     | head -n1 | cut -d " " -f5)";
	else echo "       >>               nano | Not installed - sudo apt install nano";
fi
if [ -x /usr/bin/neofetch ] 
	then echo "       >>           neofetch | $(neofetch --version | cut -d " " -f2)";
	else echo "       >>           neofetch | Not installed - sudo apt install neofetch";
fi
if [ -x /usr/bin/terminator ] 
	then echo "       >>         terminator | $(terminator --version | head -n1 | cut -d " " -f2)";
	else echo "       >>         terminator | Not installed - sudo apt install terminator";
fi
if [ -x /usr/bin/vim ] 
	then echo "       >>                vim | $(vim --version      | head -n1 | cut -d " " -f5-5)";
	else echo "       >>                vim | Not installed - sudo apt install vim";
fi
if [ -x /usr/bin/wordgrinder ] 
	then echo "       >>        wordgrinder | $(wordgrinder -h     | head -n1 | cut -d " " -f3)";
	else echo "       >>        wordgrinder | Not installed - sudo apt install wordgrinder";
fi
echo "    +-------------------------------------------------+"
echo "    |       </$(whoami | tr '[:lower:]' '[:upper:]')'S INSTALLED GUI PROGRAMS>       |"
echo "    +-------------------------------------------------+"
if [ -x /usr/bin/brave-browser ] 
	then echo "       >>      brave browser | $(brave-browser --version | cut -d " " -f3)";
	else echo "       >>      brave browser | Not installed - See https://brave.com/linux/#linux";
fi
if [ -x /usr/bin/easytag ] 
	then echo "       >>            easytag | $(easytag --version  | head -n1 | cut -d " " -f2)";
	else echo "       >>            easytag | Not installed - sudo apt install easytag";
fi
if [ -x /usr/bin/filezilla ] 
	then echo "       >>          filezilla |$(filezilla -v        | head -n2 | cut -c 10-16 | tail +2)";
	else echo "       >>          filezilla | Not installed - sudo apt install filezilla";
fi
if [ -x /usr/bin/gnome-tweaks ] 
	then echo "       >>       gnome-tweaks | $(gnome-tweaks --version)";
	else echo "       >>       gnome-tweaks | Not installed - sudo apt install gnome-tweaks";
fi
if [ -x /usr/sbin/gsmartcontrol ] 
	then echo "       >>      gsmartcontrol | $(gsmartcontrol --version | head -n2 | cut -d " " -f3    | tail +2)";
	else echo "       >>      gsmartcontrol | Not installed - sudo apt install gsmartcontrol";
fi
if [ -x /usr/bin/ophcrack ] 
	then echo "       >>           ophcrack | $(ophcrack -h        | head -n1 | cut -d " " -f2)";
	else echo "       >>           ophcrack | Not installed - sudo apt install ophcrack";
fi
if [ -x /usr/bin/subl ] 
	then echo "       >>       sublime-text | $(subl --version     | cut -d " " -f3-4)";
	else echo "       >>       sublime-text | Not installed - See https://www.sublimetext.com/docs/linux_repositories.html";
fi
if [ -x /usr/sbin/synaptic ] 
	then echo "       >>           synaptic | $(/usr/sbin/synaptic --help  | head -n1 | cut -d " " -f4)";
	else echo "       >>           synaptic | Not installed - sudo apt install synaptic";
fi
if [ -x /usr/bin/thunderbird ] 
	then echo "       >>        thunderbird | $(thunderbird --version      | cut -d " " -f3)";
	else echo "       >>        thunderbird | Not installed - sudo apt install thunderbird";
fi
if [ -x /snap/bin/vlc ] 
	then echo "       >>                vlc | $(vlc --version 2>&1 < /dev/null | head -n1 | cut -d " " -f3)";
	else echo "       >>                vlc | Not installed - sudo snap install vlc";
fi

echo "    +-------------------------------------------------+"
echo "    |               </LIBRARIES TOOLS>                |"
echo "    +-------------------------------------------------+"
echo "       >>      BINUTILS | http://fr.linuxfromscratch.org/view/lfs-systemd-stable/chapter08/binutils.html#contents-binutils"
echo "       >>     COREUTILS | http://fr.linuxfromscratch.org/view/lfs-systemd-stable/chapter08/coreutils.html#contents-coreutils"
echo "       >>     FINDUTILS | http://fr.linuxfromscratch.org/view/lfs-systemd-stable/chapter08/findutils.html#contents-findutils"
echo "       >>       G++/GCC | http://fr.linuxfromscratch.org/view/lfs-systemd-stable/chapter08/gcc.html#contents-gcc"
echo "       >>         GLIBC | http://fr.linuxfromscratch.org/view/lfs-systemd-stable/chapter08/glibc.html#contents-glibc"
echo "       >>          GZIP | http://fr.linuxfromscratch.org/view/lfs-systemd-stable/chapter08/gzip.html#contents-gzip"
echo "       >>       NCURSES | http://fr.linuxfromscratch.org/view/lfs-systemd-stable/chapter08/ncurses.html#contents-ncurses"

#-- G++ TEST COMPILATION --#
echo ""
echo "    +-------------------------------------------------+"
echo "    |              </G++ COMPILATION TEST>            |"
echo "    +-------------------------------------------------+"
echo 'int main(){}' > testcomp.c && g++ -o testcomp testcomp.c
if [ -x testcomp ]
  then echo "                    COMPILATION   >> DONE";
  else echo "       >> ERROR ! g++ may not be installed or may be corrupted... Please reinstall it";
fi
rm -f testcomp.c testcomp
echo ""
