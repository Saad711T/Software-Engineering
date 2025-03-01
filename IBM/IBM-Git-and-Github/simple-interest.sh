#!/bin/bash
# Simple Interest Calculation
echo "Enter the principal amount:"
read principal
echo "Enter the annual interest rate:"
read rate
echo "Enter the number of years:"
read time

interest=$(echo "$principal * $rate * $time / 100" | bc)
echo "Simple Interest: $interest"
