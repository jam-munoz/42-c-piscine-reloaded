#!/bin/bash
ifconfig | grep --only-matching --extended-regexp '([[:xdigit:]]{1,2}:){5}[[:xdigit:]]{1,2}'