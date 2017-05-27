#!/bin/bash
scp $1 chip@192.168.1.121:/home/chip
ssh chip@192.168.1.121 "./$1"
