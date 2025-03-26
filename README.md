# 🧠 Let's Play — Game Server Backend

## 📘 Overview

This repository contains the server-side backend for the educational game platform Let's Play, developed for the course CE-2103 — Algoritmos y Estructuras de Datos II at Instituto Tecnológico de Costa Rica.

The system hosts logic and communication for two interactive games:
- **BP Game**: a table-based game with pathfinding and backtracking.
- **Genetic Puzzle**: an image-based puzzle solved using genetic algorithms.

The server handles all **game logic**, **player coordination**, and **data transmission** using **TCP/IP sockets**, while the client is responsible for the graphical interface.

---

## ⚙️ Responsibilities

- Handle **multi-client connections** via TCP/IP
- Process player inputs and game state updates
- Execute logic for:
  - 🧭 Pathfinding algorithms
  - 🔁 Backtracking solutions
  - 🧬 Genetic simulation
- Communicate real-time updates to the Unity-based client

---

## 🧰 Technologies

- **Language**: C++
- **Platform**: Windows 10
- **IDE**: Visual Studio Community 2019
- **Protocol**: TCP/IP socket communication
- **Integration**: Compatible with Unity 2020.3.7f1 game clients

---

## 📎 Related

Client and game interface repository:  
🔗 [Let's Play — Client + Games](https://github.com/MAU143429/LetsPlay-CE-2103)
