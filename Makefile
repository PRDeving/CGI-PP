compile:
	g++ -Wall -Iincludes src/request.cpp src/keyvalue.cpp src/main.cpp -o cpp.cgi

install: 
	sudo mkdir -p /var/www/cgi-bin; \
		sudo mv cpp.cgi /var/www/cgi-bin; \
		if [ -d "/etc/apache2" ]; then \
		if [ -d "/etc/apache2/mods-enabled/cgi.load"]; then \
		echo "modules cgi already enabled"; \
		else sudo cp /etc/apache2/mods-available/cgi* /etc/apache2/mods-enabled; \
		fi; \
		sudo service apache2 restart; \
		fi; \
		if [ -d "/etc/httpd" ]; then \
		sudo service httpd restart; \
		fi;

deploy: compile
	ssh -t user@192.168.1.41 'cd /home/user/CGI-PP; git pull; make; sudo make install'
