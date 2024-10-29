# from flask import Flask, request
# from twilio.twiml.messaging_response import MessagingResponse
# import pandas as pd
# app = Flask(__name__)

# @app.route('/whatsapp', methods=['POST'])
# def whatsapp_reply():
#     # Get the message from the user
#     incoming_msg = request.values.get('Body', '').lower()

#     # Create a Twilio response object
#     response = MessagingResponse()
#     message = response.message()

#     # Respond based on the content of the incoming message
#     if 'sup' in incoming_msg:
#         message.body('Hi!fdfdf    i wont and i  can I help you today?')
#     else:
#         message.body('I am a chatbot. Please say "hello" to start a conversation.')

#     return str(response)

# if __name__ == '__main__':
#     app.run(debug=True)


from flask import Flask, request
from twilio.twiml.messaging_response import MessagingResponse
import data_loader  
app = Flask(__name__)

@app.route('/whatsapp', methods=['POST'])
def whatsapp_reply():
    incoming_msg = request.values.get('Body', '').lower()


    response = MessagingResponse()
    message = response.message()
    print(incoming_msg)


    parts = incoming_msg.split()
    if len(parts) == 2:
        day = parts[0]
        meal = parts[1]
        

        menu_items = data_loader.get_menu(day, meal)
        
        # Format the response message
        if isinstance(menu_items, list):
            # Join the list of items into a string
            menu_response = f"{day.capitalize()} {meal.capitalize()} menu:\n" + "\n".join(menu_items)
        else:
            # Handle cases where the response is not a list (error message)
            menu_response = menu_items
    else:
        # Default response for unrecognized format
        menu_response = 'Please provide a valid input in the format "day meal" (e.g., "monday dinner").'

    # Set the response message
    message.body(menu_response)

    return str(response)

if __name__ == '__main__':
    app.run(debug=True)



# if __name__ == '__main__':
#     app.run(debug=True, host='0.0.0.0', port=int(os.environ.get('PORT', 5000)))


