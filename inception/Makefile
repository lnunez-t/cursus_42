all:
	@mkdir -p ~/data/wordpress
	@mkdir -p ~/data/mysql
	sudo hostsed add 127.0.0.1 lnunez-t.42.fr
	sudo docker compose -f ./srcs/docker-compose.yml up -d --build

down:
	sudo docker compose -f ./srcs/docker-compose.yml down

re:
	sudo hostsed add 127.0.0.1 lnunez-t.42.fr
	sudo docker compose -f ./srcs/docker-compose.yml up -d --build --force-recreate

clean:
	sudo hostsed remove 127.0.0.1 lnunez-t.42.fr
	sudo docker system prune -af

.PHONY:
	all down re clear