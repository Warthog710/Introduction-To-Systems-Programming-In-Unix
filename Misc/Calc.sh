#!/bin/bash

#Asking and reading user input
echo "Please enter the first operand"
read op1

echo "Please enter the second operand"
read op2

echo "Please enter the operator"
read operator

#Operator equals +
if [ "$operator" = "+" ]; then
    answer=$((${op1}+${op2}))
    echo "$op1 + $op2 = $answer"
fi

#Operator equals -
if [ "$operator" = "-" ]; then
    answer=$((${op1}-${op2}))
    echo "$op1 - $op2 = $answer"
fi

#Operator equals *
if [ "$operator" = "*" ]; then
    answer=$((${op1}*${op2}))
    echo "$op1 * $op2 = $answer"
fi

#Operator equals /
if [ "$operator" = "/" ]; then
    answer=$((${op1}/${op2}))
    echo "$op1 / $op2 = $answer"
fi