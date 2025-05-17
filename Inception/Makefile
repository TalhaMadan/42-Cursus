DC := docker-compose -f ./srcs/docker-compose.yml

all:
	@mkdir -p /home/data/wordpress
	@mkdir -p /home/data/mysql
	@$(DC) up -d --build

down:
	@$(DC) down

re: clean all

clean:
	@$(DC) down -v --remove-orphans
	@docker rmi -f $$(docker images -q)

clean_wp:
	sudo docker volume rm srcs_wordpress_data
	sudo rm -rf /home/data/wordpress/*


.PHONY: all down re clean