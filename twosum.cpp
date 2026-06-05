# Docker Basic Commands (From Scratch)

## 1. Check Docker Version

```bash
docker --version
```

```bash
docker version
```

---

## 2. Check Docker Information

```bash
docker info
```

---

# IMAGES

## 3. Download Image

```bash
docker pull nginx
```

```bash
docker pull ubuntu
```

---

## 4. List Downloaded Images

```bash
docker images
```

---

## 5. Remove Image

```bash
docker rmi nginx
```

---

# CONTAINERS

## 6. Run Container

```bash
docker run nginx
```

---

## 7. Run Container in Background

```bash
docker run -d nginx
```

---

## 8. Run Container with Name

```bash
docker run -d --name mynginx nginx
```

---

## 9. Run Container with Port Mapping

```bash
docker run -d -p 8080:80 nginx
```

Open in browser:

```txt
http://localhost:8080
```

---

## 10. List Running Containers

```bash
docker ps
```

---

## 11. List All Containers

```bash
docker ps -a
```

---

## 12. Stop Container

```bash
docker stop mynginx
```

---

## 13. Start Container

```bash
docker start mynginx
```

---

## 14. Restart Container

```bash
docker restart mynginx
```

---

## 15. Remove Container

```bash
docker rm mynginx
```

---

## 16. Force Remove Running Container

```bash
docker rm -f mynginx
```

---

# INSIDE CONTAINER

## 17. Open Terminal Inside Container

```bash
docker exec -it mynginx bash
```

For alpine containers:

```bash
docker exec -it container_name sh
```

---

## 18. Run Linux Commands Inside Container

```bash
ls
```

```bash
pwd
```

```bash
apt update
```

Exit:

```bash
exit
```

---

# LOGS

## 19. View Logs

```bash
docker logs mynginx
```

---

## 20. Live Logs

```bash
docker logs -f mynginx
```

---

# DOCKERFILE

## 21. Create Dockerfile

```dockerfile
FROM node:18

WORKDIR /app

COPY . .

RUN npm install

EXPOSE 3000

CMD ["npm","start"]
```

---

## 22. Build Docker Image

```bash
docker build -t myapp .
```

---

## 23. Run Built Image

```bash
docker run -d -p 3000:3000 myapp
```

---

# VOLUMES

## 24. Create Volume

```bash
docker volume create myvolume
```

---

## 25. List Volumes

```bash
docker volume ls
```

---

## 26. Attach Volume

```bash
docker run -d -v myvolume:/app/data nginx
```

---

# NETWORKS

## 27. List Networks

```bash
docker network ls
```

---

## 28. Create Network

```bash
docker network create mynetwork
```

---

## 29. Run Container on Network

```bash
docker run -d --network mynetwork --name c1 nginx
```

---

# DOCKER COMPOSE

## 30. Check Compose Version

```bash
docker compose version
```

---

## 31. docker-compose.yml

```yaml
services:
  web:
    image: nginx
    ports:
      - "8080:80"
```

---

## 32. Start Compose

```bash
docker compose up
```

Background:

```bash
docker compose up -d
```

---

## 33. Stop Compose

```bash
docker compose down
```

---

# CLEANUP COMMANDS

## 34. Remove Stopped Containers

```bash
docker container prune
```

---

## 35. Remove Unused Images

```bash
docker image prune
```

---

## 36. Remove Everything Unused

```bash
docker system prune -a
```

---

# COMPLETE FLOW (Most Important)

## Pull Image

```bash
docker pull nginx
```

## Run Container

```bash
docker run -d -p 8080:80 --name mynginx nginx
```

## Check Running Containers

```bash
docker ps
```

## Open Website

```txt
http://localhost:8080
```

## Stop Container

```bash
docker stop mynginx
```

## Remove Container

```bash
docker rm mynginx
```

## Remove Image

```bash
docker rmi nginx
```

---

# MOST IMPORTANT COMMANDS FOR BEGINNERS

```bash
docker pull
docker run
docker ps
docker stop
docker start
docker rm
docker rmi
docker exec
docker logs
docker build
docker compose up
docker compose down
```
