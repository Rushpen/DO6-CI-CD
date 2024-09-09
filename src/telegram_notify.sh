#!/bin/bash

BOT_TOKEN=$(grep 'BOT_TOKEN' data_for_bot.txt | cut -d'=' -f2 | tr -d '"')
CHAT_ID=$(grep 'CHAT_ID' data_for_bot.txt | cut -d'=' -f2 | tr -d '"')


SUCCESS_MESSAGE="✅ All stages of the CI/CD pipeline completed successfully!"

curl -s -X POST "https://api.telegram.org/bot${BOT_TOKEN}/sendMessage" \
    -d chat_id="${CHAT_ID}" \
    -d text="${SUCCESS_MESSAGE}"