# 📚 Embedded Linux Exercise 3 : OrangePi Zero 2 Plus

Welcome to the Embedded Linux exercise for setting up and exploring the **OrangePi Zero 2 Plus** board. Follow the steps below to configure the board, connect to networks, and implement tasks to deepen your understanding of embedded systems. 🚀

# Assignment Submission Instructions

Push your repository to your GitHub account and set it to public. I will clone the repository and assign your grade based on its contents. Additionally, record a video (using your phone, not screen recording) demonstrating the stages of your code (e.g., development or execution). Create a text file named `repolink.txt` containing only your GitHub repository URL. Package the video, the repository folder, and `repolink.txt` into a single ZIP file named `RTES2025_HW3_{student_number}.zip`, where `{student_number}` is your student ID. Upload the ZIP file to CW. Answer the assignment questions in the repository's `README.md` file using Markdown syntax.

The ZIP file should follow this directory structure:

```
RTES2025_HW3_401234567
├── HW3.mp4  # Supported formats: mp4, mkv, mpeg, or similar
├── repolink.txt       # Contains the GitHub repository URL
└── RTES2025_HW3       # Repository folder
    ├── auto-wifi-connect
    ├── ipc
    └── ...
```

---

### 🛠️ Setting Up the OrangePi Zero 2 Plus
Follow the instructional video to configure the OrangePi Zero 2 Plus board.

---

### 🌐 Wi-Fi and SSH Connection
1. Create a Wi-Fi hotspot using your phone 📱 or laptop 💻 with a custom SSID and password. Ensure the frequency is set to **2.4 GHz** and internet access is enabled.
   - **💡 Tip**: Use the `nmcli` command to connect to Wi-Fi.
   - **💡 Tip**: Connect to the board via SSH using the **Remote – SSH** extension in VS Code or an SSH client (e.g., PuTTY) for a smoother workflow.

---

### 🗂️ Introduction to Git
Clone the provided repository 📂 using SSH. The repository contains incomplete code and testing tools for the tasks below.
---

### 📡 Automatic Wi-Fi Connection
Write a shell script 🖥️ using `nmcli` to automatically connect to a specified Wi-Fi network (e.g., **MySSID**) if the device is not already connected.
- Schedule the script to run **every minutes** using a **cron job**.
- Configure the script to execute once at **system boot** using the cron `@reboot` directive.
- Log connection status, available Wi-Fi networks, and other relevant details to a file named `auto-connect.log`.

---

### 🔗 Inter-Process Communication Mechanisms
Explore three inter-process communication (IPC) methods to understand task communication in Linux:
1. **FIFO** 📥📤
2. **Linux Signals** ⚡
3. **Shared Memory** 🗄️

#### 1. FIFO
Complete the provided `fifo-sender.sh` and `fifo-receiver.sh` scripts in the GitHub repository. When executed:
- The sender script should create a FIFO (if it doesn't exist) and transmit terminal input to the receiver via the FIFO.
- The receiver should display the input immediately.

#### 2. Linux Signals
Complete the provided C++ programs `signal-receiver.cpp` and `signal-sender.cpp`:
- **Receiver** 🖨️: Prints its **PID** on startup, waits for signals, and logs each received signal to a file.
- **Sender** 📩: Accepts a PID and signal number as command-line arguments and sends the signal to the specified process.

Answer the following:
### 🔹 Difference between SIGINT and SIGKILL
- **SIGINT** (`signal 2`): Sent when you press `Ctrl+C`. Can be **caught, ignored, or handled** by the process.
- **SIGKILL** (`signal 9`): Immediately terminates the process. **Cannot be caught, ignored, or handled**.

### 🔹 Signals that can be caught or handled
- Most signals **except** `SIGKILL (9)` and `SIGSTOP (19)` can be caught or handled using signal handlers.

### 🔹 Number of signals in Linux
- Typically, **64 signals** are defined (`1–64`) in modern Linux systems (check with `kill -l`).
#### 3. Shared Memory
Complete the provided C++ programs `shm-writer.cpp` and `shm-reader.cpp`:
- **Writer** ✍️: Creates a shared memory segment and writes user input into a **10-character circular buffer**.
- **Reader** 📖: Reads and displays the contents of the shared memory upon execution.

Answer the following:
### 🔹 Key Differences Between FIFO and Shared Memory (IPC)

| Feature           | FIFO (Named Pipe)                  | Shared Memory                         |
|------------------|------------------------------------|---------------------------------------|
| **Speed**         | Slower (uses kernel buffers)       | Faster (direct memory access)         |
| **Data Flow**     | Unidirectional or bidirectional    | Bidirectional                         |
| **Persistence**   | Exists as a file in the filesystem | Exists in memory only                 |
| **Setup**         | Easier to set up                   | Requires synchronization mechanisms   |
| **Communication** | Through file I/O                   | Through memory read/write             |
| **Use Case**      | Simple command/data passing        | High-performance, large data sharing  |

---

### 🌍 Basic Web Server
Complete the provided shell script 🌐 to create a simple web server that listens on **port 80** and responds to HTTP requests with the system’s current **date and time**.
- It should print the response in the terminal too when run by terminal.
- Create a Systemd Service (webserver.service) so that:
    Start after the network is online (connected to wifi).
    Restart automatically if the script exits (with a 5-second delay).
    Log output and errors to the system journal.
    Run on system boot.
You should put the service file behind the webserver script in the submission and in the repository.

- **💡 Tip**: Use the `nc` (netcat) command for handling network connections.
    
---

### 📚 Useful Reference Websites
- **OrangePi Documentation**: [Official OrangePi Wiki](http://www.orangepi.org/orangepiwiki/) – Guides for setting up OrangePi boards.
- **Linux Networking**: [nmcli Documentation](https://networkmanager.dev/docs/api/latest/nmcli.html) – Manage Wi-Fi with `nmcli`.
- **Git Basics**: [Git SCM](https://git-scm.com/doc) – Official Git documentation for cloning and managing repositories.
- **Systemd Services**: [Systemd Documentation](https://www.freedesktop.org/software/systemd/man/systemd.service.html) – Guide to creating systemd services.
- **Linux IPC**: [Beej’s Guide to IPC](https://beej.us/guide/bgipc/) – Comprehensive resource on FIFO, signals, and shared memory.
- **Netcat Usage**: [Netcat Manual](http://nc110.sourceforge.net/) – Learn how to use `nc` for networking tasks.

---

Happy coding! 🎉
