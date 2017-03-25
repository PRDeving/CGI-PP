compile: tests run-tests
	g++ -Wall -Iincludes src/keyvalue.cpp src/parser.cpp src/filesystem.cpp src/request.cpp src/router.cpp src/main.cpp -o cpp.cgi

install: 
	sudo mkdir -p /usr/lib/cgi-bin; \
		sudo mv cpp.cgi /usr/lib/cgi-bin; \
		if [ -d "/etc/apache2" ]; then \
		if [ -d "/etc/apache2/mods-enabled/cgi.load"]; then \
		echo "modules cgi already enabled"; \
		else sudo cp /etc/apache2/mods-available/cgi* /etc/apache2/mods-enabled; \
		fi; \
		if [ -d "/etc/apache2/conf-enabled/serve-cgi-bin.conf"]; then \
		echo "conf cgi already enabled"; \
		else sudo cp /etc/apache2/conf-available/serve-cgi-bin* /etc/apache2/conf-enabled; \
		fi; \
		sudo service apache2 restart; \
		fi; \
		if [ -d "/etc/httpd" ]; then \
		sudo service httpd restart; \
		fi;

deploy: compile
	ssh -t user@192.168.1.38 'cd /home/user/CGI-PP; git pull; make; sudo make install'

tests:
	cd test; make

run-tests:
	cd test; ./tests
