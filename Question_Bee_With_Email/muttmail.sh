#!/bin/bash
echo $3 | mutt -s "National Geographic Quiz - Scores" $1 -a $2 
