import time
import requests

# Function to fetch a random quote from the QuotationsPage API
def get_random_quote():
    response = requests.get("https://api.quotationspage.com/quote/{}".format(time.time()))
    quote_data = response.json()
    return quote_data["quote"]

# Set the total duration to run the program (5 minutes)
total_duration = 5 * 60  # 5 minutes in seconds

# Start time
start_time = time.time()

# Run the loop for 5 minutes
while time.time() - start_time < total_duration:
    # Fetch and print a random quote
    quote = get_random_quote()
    print("Quote:", quote)

    # Wait for 2 seconds before fetching the next quote
    time.sleep(2)



# import requests
# import pyautogui as py
# import time

# py.hotkey('alt', 'tab')

# # Adding a delay after switching to the application
# time.sleep(2)

# with open("input.txt", "r") as file:
#     for line in file:
#         time.sleep(5)
#         py.typewrite(line.strip())  # Corrected the function and removed newline characters
#         py.press("enter")
        

# print("hello")

# py.hotkey('alt', 'tab')

# # Adding a delay after switching to the application
# time.sleep(2)

# for i in range(10000):
    
# 	# Fetch birthday-related quotes from the Quotable API
# 	response = requests.get("https://api.quotable.io/random")
# 	quote_data = response.json()
# 	quote_text = quote_data["content"]

# 	# Type the birthday quote
# 	time.sleep(5)
# 	py.typewrite(quote_text)

# 	# Press Enter
# 	py.press("enter")

# 	print("Birthday Quote typed:", quote_text)
