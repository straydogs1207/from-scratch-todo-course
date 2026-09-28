# From-Scratch Todo List & Systems Engineering Course

> Building a full-stack Todo application from first principles without frameworks: custom SQLite-style B-Tree storage engine, raw callback-driven socket HTTP server, and custom Virtual DOM / reconciler.

---

## Curriculum & Roadmap

1. **Module 1: The Storage Engine (Mini SQLite from Scratch)**
   - *Reference*: cstack's *Let's Build a Simple Database*
   - Fixed-size record serialization, page layout (4096-byte pages), file pager, and B-Tree structure.
2. **Module 2: Low-Level Networking & Callback-Driven HTTP Server**
   - *Reference*: Beej's *Guide to Network Programming* & The C10K Problem
   - TCP sockets, non-blocking I/O multiplexing (), callback event loop, manual HTTP/1.1 parsing.
3. **Module 3: Frontend Virtual DOM & Custom Reconciler**
   - *Reference*: Rodrigo Pombo's *Didact* & Jason Yu's VDOM Breakdown
   - VNode representation, tree diffing, patch operations, commit phase to real browser DOM.
4. **Module 4: Full-Stack Integration**
   - REST API over raw sockets, database CRUD integration, reactive Todo client.

---

## Learning Log & Dialogue

### 👤 Learner

remember this for this chat 

You are an expert AI tutor and technical instructor. 

Your goal is to teach me complex machine learning and distributed systems topics (e.g., Distributed Training, Parallelism Strategies, FlashAttention, Transformer Architecture, GPU Optimization) by referencing my personal blog posts and notes, structuring everything into structured, self-contained courses one course at a time.

Please follow these guidelines:

1. One Course at a Time:
   - Organize the overall curriculum into distinct, modular courses.
   - Deliver one course at a time, broken down into logical modules/lessons.
   - Do not jump ahead until we have thoroughly covered and verified understanding of the current topic.

2. Grounded in Blog/articles
   - Use blog posts of popular people who have taught the same thing as reference.

3. First-Principles & Deep Rigor:
   - Do not stop at high-level abstractions or hand-wavy summaries.
   - Explain the exact mathematical formulation, tensor shapes (batch, sequence length, heads, hidden dimensions), memory footprints, and compute operations.
   - Clearly delineate where data flows, which GPUs compute what, and where/why communication collectives (All-Reduce, All-Gather, Reduce-Scatter, P2P) occur.
   - Address hardware realities: memory bandwidth, compute bounds, NVLink vs. InfiniBand, and activation memory.

4. Interactive & Engaging:
   - Use clear ASCII diagrams and tensor shape walk-throughs.
   - Pause to check my understanding with targeted questions or quick self-check problems.
   - Always be ready to dive into the low-level details (code, CUDA kernels, PyTorch internals) whenever I ask.

<USER_SETTINGS_CHANGE>
The user changed setting `Model Selection` from None to Gemini 3.8 Flash (High). No need to comment on this change if the user doesn't ask about it. If reporting what model you are, please use a human readable name instead of the exact string.
</USER_SETTINGS_CHANGE>

### 🤖 Instructor

Understood. I have locked in these instructions and will act as your dedicated AI tutor and technical instructor for Machine Learning, GPU Systems, and Distributed Training.

Here is how we will operate:

- **Strict modularity**: We tackle **one course at a time**, broken down into sequential, rigorous lessons. We do not advance until you feel solid and we've verified your understanding.
- **Reference-grounded**: Rooted in high-signal industry references (e.g., Lilian Weng, Horace He, Stas Bekman, Tri Dao, Rajbhandari et al. / DeepSpeed, Megatron-LM, Hugging Face research).
- **First-principles rigor**: Every topic will trace exact tensor shapes $(B, S, H, D)$, memory budgets (parameters, gradients, optimizer states, activations), arithmetic intensity vs. memory bandwidth (Roofline model, SRAM vs. HBM), and exact collective communication patterns (All-Reduce, Reduce-Scatter, All-Gather, P2P).
- **Interactive delivery**: Expect structured ASCII pipeline/memory diagrams, tensor traces, and targeted checkpoint questions before moving to next concepts.

---

### Potential Course Catalog

To set our roadmap, here are five core courses we can cover. We will pick **one** to start:

1. **Course 1: GPU Architecture, Memory Hierarchy, & Kernel Fundamentals**
   * *Focus*: SMs, Warps, Register Files, Shared Memory (SRAM) vs. HBM, Roofline model, Memory Bandwidth bounds vs. Compute bounds, Triton/CUDA mental model.
2. **Course 2: Transformer Architecture & Memory Profiling from Scratch**
   * *Focus*: MHA/GQA/MQA exact FLOP count, KV-cache dynamics, activation memory analysis, FlashAttention (tiling, online softmax, backward pass recomputation).
3. **Course 3: Distributed Data Parallelism & Memory Reductions (DDP, ZeRO, FSDP)**
   * *Focus*: Ring/Tree All-Reduce, gradient bucketing, ZeRO-1/2/3 memory breakdowns, FSDP forward/backward communication hooks (All-Gather + Reduce-Scatter).
4. **Course 4: Model & Sequence Parallelism (Megatron-LM & Context Parallelism)**
   * *Focus*: Tensor Parallelism (Row/Col linear splits, $f$ and $g$ operators), Sequence Parallelism, Pipeline Parallelism (1F1B, bubbles, activation stashing), Context Parallelism (Ring Attention).
5. **Course 5: Training Efficiency, Quantization, & Advanced Systems**
   * *Focus*: Mixed precision (FP16/BF16/FP8 loss scaling and dynamic ranges), Activation Checkpointing/Offloading, Overlapping compute/communication (`torch.compile`, CUDA streams).

---

### How would you like to start?

1. **Select a starting course** from above (or propose a customized one).
2. If you have specific **personal notes, blog posts, or articles** you want us to anchor the first course to, share them or let me know, and we will build the syllabus directly around them.

### 👤 Learner

no these course were just an example i will give you now what i want to learn

### 👤 Learner

no these course were just an example i will give you now what i want to learn

### 🤖 Instructor

Understood! Please share the topic, notes, or blog posts you'd like us to focus on, and we will build the course and dive straight into it.

### 👤 Learner

teach me how to make a todo list website with sqlite database without using any frameworks like react (but do write our own reconciler) for backend write everything yourself all the socket programing etc, dont use coroutines though use callbacks (coroutines are very hard for you rn), make the database yourself

follow a human written resource(articles,blogs) for each thing or you can teach them by yourself , take that as refrence then teach me 
imp - remember you have to teach me do not make this whole thing yourself at all just break it into parts and teach me every topic and things necessary to build it

### 🤖 Instructor

This is an exceptional project. By stripping away every layer of modern abstraction—React, Express, ORMs, and async/await syntax—you will understand how web browsers, network stacks, operating system I/O multiplexers, and database engines actually work under the hood.

Here is our strict operational contract:
1. **Zero boilerplate dumping**: I will not hand you a finished codebase. We will build this piece by piece, starting from mental models, diagrams, and bare-metal primitives.
2. **Callback-driven concurrency only**: No `async`, `await`, promises, or coroutines. We will use non-blocking sockets with OS-level I/O multiplexing (`select`/`poll`) and register explicit callback handlers for readable/writable events.
3. **Reference-grounded**: Every module is anchored in classic, human-written engineering literature.

---

### The 4-Module Curriculum

```
+-----------------------------------------------------------------------+
| MODULE 1: The Storage Engine (Mini SQLite from Scratch)               |
| - Reference: cstack's "Let's Build a Simple Database"                 |
| - Concepts: Pages, File Pager, Row Serialization, Disk Layout, B-Tree |
+-----------------------------------------------------------------------+
                                  |
                                  v
+-----------------------------------------------------------------------+
| MODULE 2: Low-Level Networking & Callback-Driven HTTP Server          |
| - Reference: Beej's Guide to Network Programming / C10K Problem       |
| - Concepts: TCP Sockets, Non-blocking I/O, `select()`, Callback Loop, |
|             Manual HTTP/1.1 Byte-Stream Parsing                       |
+-----------------------------------------------------------------------+
                                  |
                                  v
+-----------------------------------------------------------------------+
| MODULE 3: The Frontend Virtual DOM & Custom Reconciler                |
| - Reference: Rodrigo Pombo's "Didact" / Jason Yu's VDOM Breakdown     
<truncated 858 bytes>
 **Python** (using only standard library `socket`, `selectors`/`select`, and `struct` for binary DB packing). Clean syntax, but exposes bare-metal OS system calls.
   - **Option B**: **C** (Maximum bare-metal, manual memory management with `malloc`/`free`, BSD sockets).
   - **Option C**: **Node.js without npm** (using bare `net` and `fs` modules, strictly callback-based).

---

### Module 1: The Storage Engine (Mini SQLite)
*Primary Reference: [cstack's "Let's Build a Simple Database"](https://cstack.github.io/db_tutorial/)*

Before a database can understand queries or SQL, it is fundamentally an engine that solves two problems:
1. **Serialization**: How do we convert structured records (e.g., `id: 1, title: "Buy milk", done: 0`) into a continuous sequence of raw bytes?
2. **The Pager**: How do we read and write these bytes to a persistent disk file without loading the entire database into RAM at once?

#### Concept 1.1: Record Serialization & Fixed-Size Layout
In a simple database table like SQLite's B-tree leaves, rows are packed into fixed-width or delimited binary formats.

Consider our `todos` table schema:
- `id`: 4-byte unsigned integer (32-bit uint)
- `title`: 64-byte fixed-length string (UTF-8, padded with null bytes `\0`)
- `is_done`: 1-byte boolean (0 or 1)

```
Total Record Size: 4 + 64 + 1 = 69 Bytes

+----------------+--------------------------------+-----------+
|   id (4B)      |          title (64B)           | is_done(1)|
| [0x00 00 00 01]| ['B','u','y',' ','m','i'...]   |   [0x00]  |
+----------------+--------------------------------+-----------+
0                4                                68          69
```

#### Checkpoint Question to Begin:
1. Which language do you prefer for the Backend & Database (**Python**, **C**, or **Node.js**)?
2. If our database page size is fixed at **4096 bytes** (4 KB, standard OS page size), and each record is **69 bytes**, how many full records can fit inside a single page, and how many bytes of internal fragmentation (slack space) remain unused per page?

### 👤 Learner

before we start like i want to share this chat on github like can you do it for me like i have an account on github and already have git installed in my laptop

### 🤖 Instructor

I've set up a dedicated Git repository for our course and exported our entire conversation and course roadmap into a clean Markdown file.

### What is ready:
- **Repository location**: `/home/ashutosh-goyal/.gemini/antigravity/scratch/from-scratch-todo-course`
- **Initial commit**: Already created on the `main` branch with [`README.md`](file:///home/ashutosh-goyal/.gemini/antigravity/scratch/from-scratch-todo-course/README.md), containing the 4-module curriculum, reference links, and our full dialogue.

---

### To push this to your GitHub:

1. Go to [github.com/new](https://github.com/new) and create a new repository (e.g. `from-scratch-todo-course`). **Leave it empty** (do *not* check "Add README" or license).
2. Copy your new repo's URL (HTTPS or SSH).

Then choose either option:

#### Option A: Tell me the repo URL
Paste your repo URL here (e.g., `git@github.com:<username>/from-scratch-todo-course.git` or `https://github.com/<username>/from-scratch-todo-course.git`), and I will configure the remote and push it for you.

#### Option B: Push directly from your terminal
Run these commands in your laptop terminal:
```bash
cd /home/ashutosh-goyal/.gemini/antigravity/scratch/from-scratch-todo-course
git remote add origin <YOUR_GITHUB_REPO_URL>
git push -u origin main
```

*(As we write the database, network server, and reconciler, we will commit every milestone so your GitHub repo turns into a complete portfolio codebase.)*

Whenever you're ready, let me know the URL or confirm you've pushed, and we'll dive right into **Module 1**!

### 👤 Learner

its showing this where is repo's url

### 🤖 Instructor

You haven't created it yet—you're on the setup screen!

Here is what to do:

1. **Scroll down to the bottom** of that webpage and click the green button that says **"Create repository"**.
2. Once you click it, GitHub will redirect you to the new repository page.

Because your username is **`straydogs1207`** and the repo name is **`from-scratch-todo-course`**, your repository URL will be:

- **SSH (Recommended if you have SSH keys set up):**
  ```text
  git@github.com:straydogs1207/from-scratch-todo-course.git
  ```
- **HTTPS:**
  ```text
  https://github.com/straydogs1207/from-scratch-todo-course.git
  ```

---

### Once you click "Create repository":

I can push it directly from here! Just let me know if you want me to push using **SSH** or **HTTPS**, or you can run this single command in your terminal:

```bash
cd /home/ashutosh-goyal/.gemini/antigravity/scratch/from-scratch-todo-course
git remote add origin git@github.com:straydogs1207/from-scratch-todo-course.git
git push -u origin main
```

### 👤 Learner

its showing this
