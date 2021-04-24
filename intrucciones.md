Compiling AmeroCash Ubuntu 16.04

sudo apt-get update -y && sudo apt-get upgrade -y

sudo apt-get --assume-yes install git unzip build-essential libssl-dev libdb++-dev libboost-all-dev libqrencode-dev libminiupnpc-dev libevent-dev obfs4proxy libcurl4-openssl-dev

git clone https://github.com/Carlos110988/AmeroCash
cd AmeroCash || exit
git checkout master
git pull

cd src
mv obj_dev obj
make -f makefile.unix

sudo yes | cp -rf AmeroCash /usr/bin/



echo "Populate amerocash.conf"
mkdir ~/.amerocash
echo -e "daemon=1\listen=1\rpcuser=user\rpcpassword=changethispassword\nativetor=0\addnode=168.235.104.237\addnode=168.235.111.42" > ~/.amerocash/amerocash.conf


echo "Updating amerocash Wallet"
cd ~/amerocash || exit
git checkout master
git pull

cd src
make -f makefile.unix

sudo yes | cp -rf amerocash /usr/bin/


echo "Back to Compiled amerocashd Binary Folder"
cd ~/amerocash/src

3) echo 3 "Compile amerocash Ubuntu 18.04"

echo "Updating linux packages"
sudo apt-get update -y && sudo apt-get upgrade -y

sudo apt-get --assume-yes install git unzip build-essential libdb++-dev libboost-all-dev libqrencode-dev libminiupnpc-dev libevent-dev obfs4proxy libssl-dev libcurl4-openssl-dev

echo "Downgrade libssl-dev"
sudo apt-get install make
wget https://www.openssl.org/source/openssl-1.0.1j.tar.gz
tar -xzvf openssl-1.0.1j.tar.gz
cd openssl-1.0.1j
./config
make depend
sudo make install
sudo ln -sf /usr/local/ssl/bin/openssl `which openssl`
cd ~
openssl version -v

echo "Installing amerocash Wallet"
git clone https://github.com/Carlos110988/AmeroCash
cd AmeroCash
git checkout master
git pull

cd src

mv obj_dev obj

make OPENSSL_INCLUDE_PATH=/usr/local/ssl/include OPENSSL_LIB_PATH=/usr/local/ssl/lib -f makefile.unix

sudo yes | cp -rf amerocashd /usr/bin/

echo "Copied to /usr/bin for ease of use"

echo "Populate amerocash.conf"
mkdir ~/.amerocash
echo -e "daemon=1\listen=1\rpcuser=user\rpcpassword=changethispassword\nativetor=0\addnode=168.235.104.237\addnode=168.235.111.42" > ~/.amerocash/amerocash.conf


4) echo 4 "Update amerocash 18.04"
echo "Updating amerocash Wallet"
cd ~/amerocash || exit
git checkout master
git pull

cd src
mv obj_dev obj
make OPENSSL_INCLUDE_PATH=/usr/local/ssl/include OPENSSL_LIB_PATH=/usr/local/ssl/lib -f makefile.unix

sudo yes | cp -rf amerocashd /usr/bin/

echo "Copied to /usr/bin for ease of use"

echo "Back to Compiled amerocashd Binary Folder"
cd ~/amerocash/src
                ;;
esac
echo Selected $choice