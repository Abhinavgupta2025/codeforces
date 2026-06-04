Here’s a full beginner-friendly Docker Volume practical step-by-step.

Goal:

1. Create a Docker volume
2. Create Container 1 and store a file in the volume
3. Create Container 2 using the same volume
4. Delete Container 1
5. Verify file still exists in Container 2
6. Delete the volume and see data disappear

---

# Step 1: Create a Volume

```bash
docker volume create myvolume
```

Check volume:

```bash
docker volume ls
```

You will see:

```bash
DRIVER    VOLUME NAME
local     myvolume
```

---

# Step 2: Create First Container

```bash
docker run -it --name container1 -v myvolume:/data ubuntu bash
```

Explanation:

* `-it` → interactive terminal
* `--name container1` → container name
* `-v myvolume:/data` → attach volume
* `ubuntu` → image
* `bash` → open shell

---

# Step 3: Create File Inside Volume

Inside container terminal:

```bash
cd /data
```

Create file:

```bash
echo "Hello from Container 1" > file.txt
```

Check:

```bash
cat file.txt
```

Output:

```bash
Hello from Container 1
```

Exit container:

```bash
exit
```

---

# Step 4: Create Second Container Using SAME Volume

```bash
docker run -it --name container2 -v myvolume:/data ubuntu bash
```

Inside second container:

```bash
cd /data
ls
```

You will see:

```bash
file.txt
```

Read file:

```bash
cat file.txt
```

Output:

```bash
Hello from Container 1
```

✅ This proves:
Both containers share same volume data.

---

# Step 5: Delete First Container

Open another terminal OR exit container2 first.

Delete container1:

```bash
docker rm container1
```

OR if running:

```bash
docker rm -f container1
```

Now container1 is deleted.

BUT volume still exists.

---

# Step 6: Check File Again in Container2

Inside container2:

```bash
cat /data/file.txt
```

Still works:

```bash
Hello from Container 1
```

✅ Important Concept:
Deleting container DOES NOT delete volume data.

---

# Step 7: Exit Container2

```bash
exit
```

---

# Step 8: Delete Container2

```bash
docker rm container2
```

---

# Step 9: Delete Volume

```bash
docker volume rm myvolume
```

Now volume is permanently deleted.

---

# Step 10: Verify Volume Deleted

```bash
docker volume ls
```

`myvolume` will not appear.

---

# Step 11: Create New Container with Same Volume Name

```bash
docker run -it --name testcontainer -v myvolume:/data ubuntu bash
```

Docker creates a NEW empty volume.

Check:

```bash
cd /data
ls
```

No file found.

✅ This proves:
Deleting volume removes all stored data.

---

# Most Important Interview/Viva Concept

## Container Storage vs Volume Storage

| Feature                           | Container Storage | Volume Storage |
| --------------------------------- | ----------------- | -------------- |
| Data survives container deletion? | ❌ No              | ✅ Yes          |
| Shared between containers?        | ❌ No              | ✅ Yes          |
| Best for database/files?          | ❌ No              | ✅ Yes          |

---

# One-Line Definition for Exam

> Docker Volume is a persistent storage mechanism that allows data to survive container deletion and be shared between multiple containers.
Here’s a full beginner-friendly Docker Volume practical step-by-step.

Goal:

1. Create a Docker volume
2. Create Container 1 and store a file in the volume
3. Create Container 2 using the same volume
4. Delete Container 1
5. Verify file still exists in Container 2
6. Delete the volume and see data disappear

---

# Step 1: Create a Volume

```bash
docker volume create myvolume
```

Check volume:

```bash
docker volume ls
```

You will see:

```bash
DRIVER    VOLUME NAME
local     myvolume
```

---

# Step 2: Create First Container

```bash
docker run -it --name container1 -v myvolume:/data ubuntu bash
```

Explanation:

* `-it` → interactive terminal
* `--name container1` → container name
* `-v myvolume:/data` → attach volume
* `ubuntu` → image
* `bash` → open shell

---

# Step 3: Create File Inside Volume

Inside container terminal:

```bash
cd /data
```

Create file:

```bash
echo "Hello from Container 1" > file.txt
```

Check:

```bash
cat file.txt
```

Output:

```bash
Hello from Container 1
```

Exit container:

```bash
exit
```

---

# Step 4: Create Second Container Using SAME Volume

```bash
docker run -it --name container2 -v myvolume:/data ubuntu bash
```

Inside second container:

```bash
cd /data
ls
```

You will see:

```bash
file.txt
```

Read file:

```bash
cat file.txt
```

Output:

```bash
Hello from Container 1
```

✅ This proves:
Both containers share same volume data.

---

# Step 5: Delete First Container

Open another terminal OR exit container2 first.

Delete container1:

```bash
docker rm container1
```

OR if running:

```bash
docker rm -f container1
```

Now container1 is deleted.

BUT volume still exists.

---

# Step 6: Check File Again in Container2

Inside container2:

```bash
cat /data/file.txt
```

Still works:

```bash
Hello from Container 1
```

✅ Important Concept:
Deleting container DOES NOT delete volume data.

---

# Step 7: Exit Container2

```bash
exit
```

---

# Step 8: Delete Container2

```bash
docker rm container2
```

---

# Step 9: Delete Volume

```bash
docker volume rm myvolume
```

Now volume is permanently deleted.

---

# Step 10: Verify Volume Deleted

```bash
docker volume ls
```

`myvolume` will not appear.

---

# Step 11: Create New Container with Same Volume Name

```bash
docker run -it --name testcontainer -v myvolume:/data ubuntu bash
```

Docker creates a NEW empty volume.

Check:

```bash
cd /data
ls
```

No file found.

✅ This proves:
Deleting volume removes all stored data.

---

# Most Important Interview/Viva Concept

## Container Storage vs Volume Storage

| Feature                           | Container Storage | Volume Storage |
| --------------------------------- | ----------------- | -------------- |
| Data survives container deletion? | ❌ No              | ✅ Yes          |
| Shared between containers?        | ❌ No              | ✅ Yes          |
| Best for database/files?          | ❌ No              | ✅ Yes          |

---

# One-Line Definition for Exam

> Docker Volume is a persistent storage mechanism that allows data to survive container deletion and be shared between multiple containers.
