# Virtual Box - Debian install

# Table of contents

- [I. SSH and Firewall](#i-ssh-and-firewall)

  - **☀️ Un service SSH sera actif sur le port 4242 uniquement.**
  - **☀️ On ne devra pas pouvoir se connecter par SSH avec l’utilisateur root.**
  - **☀️ Configurer votre OS avec le pare-feu UFW ne laisser ouvert que le port 4242.**

- [II. Hostname](#ii-hostname)
  - **☀️ Hostname votre login suivi de 42**
- [III. SUDO](#iii-sudo)
  - **☀️ `ilymegy` appartiendra aux groupes user42 et sudo**
  - **☀️ Mettre en place une configuration stricte dans votre groupe `sudo`**
- [IV. Installing tools](#iv-installing-tools)
- [V. Monitoring](#v-monitoring)
  - **☀️ Mettre en place un petit script nommé `monitoring.sh`**
- [VI. BONUS](#vi-bonus)
  - [Partitions](#partitions)
  - [Web Server](#web-server)
  <p>&nbsp;</p>
  <p>&nbsp;</p>
sda5_crypt : root
mdp : 363936Im!!

# I. SSH and Firewall

Port forwarding :

![VM settings](https://cdn.discordapp.com/attachments/889061317321838627/1113024346739458068/Screenshot_from_2023-05-30_10-40-28.png)

![port forwarding rules](https://media.discordapp.net/attachments/889061317321838627/1113024346999488532/Screenshot_from_2023-05-30_10-41-17.png?width=940&height=588)

    sudo apt-get update
    sudo apt install openssh-server
    sudo systemctl status ssh

<p>&nbsp;</p>

[](https://emojipedia.org/fr/soleil/)

**☀️ Un service SSH sera actif sur le port 4242 uniquement.**

**☀️ On ne devra pas pouvoir se connecter par SSH avec l’utilisateur root.**

![ssh config](https://cdn.discordapp.com/attachments/889061317321838627/1113028977192345643/Screenshot_from_2023-05-30_10-59-33.png)

`sudo systemctl restart ssh`

<p>&nbsp;</p>

Connection on host machine :

    ssh -p 4141 ilymegy@127.0.0.1

<p>&nbsp;</p>

**☀️ configurer votre OS avec le pare-feu UFW ne laisser ouvert que le port 4242.**

Add ssh to firewall :

    sudo apt-get install ufw -y
    sudo ufw enable
    > Command may disrupt existing ssh connections. Proceed with operation (y|n)? y
    Firewall is active and enabled on system startup

    sudo ufw allow 4242/tcp
    sudo ufw reload
    sudo ufw status

![ufw status](https://cdn.discordapp.com/attachments/889061317321838627/1113039743370924082/Screenshot_from_2023-05-30_11-42-23.png)

<p>&nbsp;</p>

# II. Hostname

**☀️ hostname votre login suivi de 42 (exemple : wil42)**

![in /etc/hostname](https://cdn.discordapp.com/attachments/889061317321838627/1113046965236805663/Screenshot_from_2023-05-30_12-11-00.png)
![in /etc/hosts](https://cdn.discordapp.com/attachments/889061317321838627/1113046965014503494/Screenshot_from_2023-05-30_12-10-19.png)

    hostname

<p>&nbsp;</p>

# III. SUDO

**☀️ `ilymegy` appartiendra aux groupes user42 et sudo**

```
cut -d: -f1 /etc/passwd
sudo groupadd user42
sudo usermod -aG root ilymegy
sudo usermod -aG user42 ilymegy
groups ilymegy
ilymegy : ilymegy root cdrom floppy audio dip video plugdev netdev user42
```

<p>&nbsp;</p>

**☀️ Pour mettre en place une configuration stricte dans votre groupe sudo, il faudra remplir les conditions suivantes :</br></br>
• L’authentification en utilisant sudo sera limitée à 3 essais en cas de mot de passe erroné.</br>
• Un message de votre choix s’affichera en cas d’erreur suite à un mauvais mot de passe lors de l’utilisation de sudo.</br>
• Chaque action utilisant sudo sera archivée, aussi bien les inputs que les outputs.</br>
• Le journal se trouvera dans le dossier /var/log/sudo/.</br>
• Le mode TTY sera activé pour des questions de sécurité.</br>
• Les paths utilisables par sudo seront restreints, là encore pour des questions de sécurité.</br>(Exemple : `/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin:/snap/bin`).**

```
 cat /etc/sudoers
# This file MUST be edited with the 'visudo' command as root.
# Please consider adding local content in /etc/sudoers.d/ instead of
# directly modifying this file.
# See the man page for details on how to write a sudoers file.
#
Defaults	env_reset
Defaults	mail_badpass
Defaults    passwd_tries=3
Defaults    badpass_message="<you message when some enter a wrong password>"
Defaults    logfile="/var/log/sudo/sudo.log"
Defaults    log_input,log_output
Defaults    requiretty
Defaults    secure_path="/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin:/snap/bin"

# Host alias specification
# User alias specification
# Cmnd alias specification
# User privilege specification
root	ALL=(ALL:ALL) ALL
ilymegy	ALL=(ALL:ALL) ALL
```

<p>&nbsp;</p>

Strong password rules :

**☀️ Pour mettre en place une politique de mot de passe fort, il faudra remplir les conditions suivantes :</br></br>
• Votre mot de passe devra expirer tous les 30 jours.  
• Le nombre minimum de jours avant de pouvoir modifier un mot de passe sera configuré à 2.</br>
• L’utilisateur devra recevoir un avertissement 7 jours avant que son mot de passe n’expire.</br>
• Votre mot de passe sera de 10 caractères minimums dont une majuscule et un chiffre, et ne devra pas comporter plus de 3 caractères identiques consécutifs.</br>
• Le mot de passe ne devra pas comporter le nom de l’utilisateur.</br>
• La règle suivante ne s’applique pas à l’utilisateur `root` : le mot de passe devra comporter au moins 7 caractères qui ne sont pas présents dans l’ancien mot de  
passe.</br>
• Bien entendu votre mot de passe `root` devra suivre cette politique**

```
sudo  apt-get install libpam-pwquality
sudo cp /etc/pam.d/common-password /etc/pam.d/common-password.bak
```

```
sudo nano /etc/pam.d/common-password

password  requisite  pam_pwquality.so retry=3 minlen=10 ucredit=-1 dcredit=-1 maxrepeat=3 reject_username difok=7 enforce_for_root
```

```
sudo nano /etc/login.defs

PASS_MAX_DAYS 30
PASS_MIN_DAYS 2
PASS_WARN_AGE 7
```

```
chage -l ilymegy

Last password change				: May 26, 2023
Password expires					: Jun 25, 2023
Password inactive					: never
Account expires						: never
Minimum number of days between password change		: 2
Maximum number of days between password change		: 30
Number of days of warning before password expires	: 7
```

Changing password :

```
sudo passwd ilymegy
> Strongmdp2709
```

<p>&nbsp;</p>

# IV. Installing tools

Installing git :

    $ apt-get update -y
    $ apt-get upgrade -y
    $ apt-get install git -y

Installing `wget` and `zip` :
> `zip` is a command line utility for compressing and decompressing files in ZIP format.</br>
> `wget` is a free and open source tool for downloading files from web repositories.

    $ sudo apt-get install wget zip

Installing `Vim` :

    $ sudo apt-get install vim

Installing `Oh my zsh` (because it is easier to use) :

    $ sh -c "$(wget https://raw.github.com/ohmyzsh/ohmyzsh/master/tools/install.sh -O -)"

<p>&nbsp;</p>

# V. Monitoring

**☀️ Mettre en place un petit script nommé `monitoring.sh`**

Dès le lancement de votre serveur, le script écrira des informations toutes les 10 minutes sur tous les terminaux.</br>
La bannière est facultative.</br>
À aucun moment la moindre erreur ne doit être visible.</br></br>
Votre script devra toujours pouvoir afficher les informations suivantes :

• L’architecture de votre système d’exploitation ainsi que sa version de kernel.</br>
• Le nombre de processeurs physiques.</br>
• Le nombre de processeurs virtuels.</br>
• La mémoire vive disponible actuelle sur votre serveur ainsi que son taux d’utilisation sous forme de pourcentage.</br>
• La mémoire disponible actuelle sur votre serveur ainsi que son taux d’utilisation sous forme de pourcentage.</br>
• Le taux d’utilisation actuel de vos processeurs sous forme de pourcentage.</br>
• La date et l’heure du dernier redémarrage.</br>
• Si LVM est actif ou pas.</br>
• Le nombre de connexions actives.</br>
• Le nombre d’utilisateurs utilisant le serveur.</br>
• L’adresse IPv4 de votre serveur, ainsi que son adresse MAC (Media Access Control).</br>
• Le nombre de commande executées avec le programme sudo.

    sudo apt-get install -y net-tools
    sudo touch /usr/local/bin/monitoring.sh
    sudo chmod 777 monitoring.sh

```
#!/bin/bash
arc=$(uname -a)
pcpu=$(grep "physical id" /proc/cpuinfo | sort | uniq | wc -l)
vcpu=$(grep "^processor" /proc/cpuinfo | wc -l)
fram=$(free -m | awk '$1 == "Mem:" {print $2}')
uram=$(free -m | awk '$1 == "Mem:" {print $3}')
pram=$(free | awk '$1 == "Mem:" {printf("%.2f"), $3/$2*100}')
fdisk=$(df -BG | grep '^/dev/' | grep -v '/boot$' | awk '{ft += $2} END {print ft}')
udisk=$(df -BM | grep '^/dev/' | grep -v '/boot$' | awk '{ut += $3} END {print ut}')
pdisk=$(df -BM | grep '^/dev/' | grep -v '/boot$' | awk '{ut += $3} {ft+= $2} END {printf("%d"), ut/ft*100}')
cpul=$(top -bn1 | grep '^%Cpu' | cut -c 9- | xargs | awk '{printf("%.1f%%"), $1 + $3}')
lb=$(who -b | awk '$1 == "system" {print $3 " " $4}')
lvmu=$(if [ $(lsblk | grep "lvm" | wc -l) -eq 0 ]; then echo no; else echo yes; fi)
ctcp=$(ss -neopt state established | wc -l)
ulog=$(users | wc -w)
ip=$(hostname -I)
mac=$(ip link show | grep "ether" | awk '{print $2}')
cmds=$(journalctl _COMM=sudo | grep COMMAND | wc -l)
wall "  #Architecture: $arc
        #CPU physical: $pcpu
        #vCPU: $vcpu
        #Memory Usage: $uram/${fram}MB ($pram%)
        #Disk Usage: $udisk/${fdisk}Gb ($pdisk%)
        #CPU load: $cpul
        #Last boot: $lb
        #LVM use: $lvmu
        #Connections TCP: $ctcp ESTABLISHED
        #User log: $ulog
        #Network: IP $ip ($mac)
        #Sudo: $cmds cmd"
```

```
sudo /usr/local/bin/monitoring.sh
sudo crontab -u root -e

*/10 * * * * /usr/local/bin/monitoring.sh
```

<p>&nbsp;</p>

# VI. BONUS

## Partitions

`lsblk`

![lsblk](https://cdn.discordapp.com/attachments/889061317321838627/1118153531040477234/Screenshot_from_2023-06-13_14-22-14.png)

<p>&nbsp;</p>

## Web Server

🧠 <b> What is Lighttpd ?</b></br>
Lighttpd is a web server designed to be fast, secure, flexible, and faithful to standards. It is optimized for environments where speed is very important because it consumes less CPU and RAM than other servers.

Lighttpd install :

``sudo apt install lighttpd``

Allow connections through port 80 with the command :</br>

```
sudo ufw allow 80
sudo ufw status

Status: active

To                         Action      From
--                         ------      ----
4242/tcp                   ALLOW       Anywhere                  
80                         ALLOW       Anywhere                  
4242/tcp (v6)              ALLOW       Anywhere (v6)             
80 (v6)                    ALLOW       Anywhere (v6)   
```

Port forwarding :

![add port 80](https://cdn.discordapp.com/attachments/889061317321838627/1118198827334242324/Screenshot_from_2023-06-13_17-22-36.png)

<p>&nbsp;</p>

🧠 <b> What is Wordpress ?</b></br> 
Wordpress is a content management system focused on the creation of any type of website.

Wordpress install :

```
cd /var/www/
sudo wget https://es.wordpress.org/latest-es_ES.zip
sudo unzip latest-en_US.zip
sudo mv html html_old
ls
➜ html_old  latest-es_ES.zip  wordpress

sudo mv wordpress html
ls
➜ html  html_old  latest-es_ES.zip

sudo chmod -R 755 html
```

<p>&nbsp;</p>

🧠 <b> What is MariaDB ?</b></br>
MariaDB is a database. It is used for various purposes, such as data warehousing, e-commerce, enterprise-level functions, and logging applications.

MariaDB install :

``sudo apt install mariadb-server``

Because the default configuration leaves your MariaDB installation unsecure, we will use a script provided by the mariadb-server package to restrict access to the server and remove unused accounts.

```
sudo mysql_secure_installation

Switch to unix_socket authentication [Y/n] n
Change the root password? [Y/n] n
Remove anonymous users? [Y/n] y
Disallow root login remotely? [Y/n] y
Remove test database and access to it? [Y/n] y
Reload privilege tables now? [Y/n] y
```
<p>&nbsp;</p>

Create the database and the user for the WordPress :

```
root@ilymegy42:/var/www# mariadb
MariaDB [(none)]> CREATE DATABASE my_db;
Query OK, 1 row affected (0.000 sec)

MariaDB [(none)]> SHOW DATABASES;
+--------------------+
| Database           |
+--------------------+
| information_schema |
| my_db              |
| mysql              |
| performance_schema |
+--------------------+
4 rows in set (0.001 sec)

MariaDB [(none)]> CREATE USER 'ilymegy'@'localhost' IDENTIFIED BY '12345';

MariaDB [(none)]> GRANT ALL PRIVILEGES ON my_db.* TO 'ilymegy'@'localhost';
Query OK, 0 rows affected (0.001 sec)

MariaDB [(none)]> FLUSH PRIVILEGES;
Query OK, 0 rows affected (0.001 sec)
```

<p>&nbsp;</p>

🧠 <b> What is PHP ?</b></br>
PHP is a programming language. It is mainly used to develop dynamic web applications and interactive websites. PHP runs on the server side.

PHP install :

``sudo apt install php-cgi php-mysql``

<p>&nbsp;</p>

**WordPress configuration**

Configure `wf-config.php` with our db informations :

```
cd /var/www/html
cp wp-config-sample.php wp-config.php
nano wp-config.php
```
![wp-config](https://cdn.discordapp.com/attachments/889061317321838627/1118199538352652418/Screenshot_from_2023-06-13_17-25-33.png)

Enabled the fastcgi-php and fastcgi-php modules :

```
sudo lighty-enable-mod fastcgi
sudo lighty-enable-mod fastcgi-php
sudo service lighttpd force-reload
```
> We enabled the fastcgi-php module to improve the performance and speed of web applications on the server and the fastcgi-php module to improve the performance and speed of PHP-based web applications on the server.

![wp-admin](https://cdn.discordapp.com/attachments/889061317321838627/1118201366062563359/Screenshot_from_2023-06-13_17-32-51.png)
