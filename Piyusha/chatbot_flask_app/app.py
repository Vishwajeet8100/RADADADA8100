from flask import Flask, request, jsonify, render_template
from datetime import datetime

app = Flask(__name__)

@app.route('/')
def index():
    return render_template('index.html')

@app.route('/chat', methods=['POST'])
def chat():
    user_message = request.json.get('message', '').lower()

    def generate_response(msg):
        if "whale" in msg:
            return (
                "Whales are magnificent marine mammals. The blue whale is the largest animal "
                "to have ever lived on Earth—reaching up to 100 feet in length!"
            )
        elif "cpp" in msg or "c++" in msg:
            return (
                "C++ is a powerful programming language widely used for system/software development, "
                "game engines, and performance-critical applications. It supports OOP and low-level memory manipulation."
            )
        elif "engineering" in msg:
            return (
                "Engineering is the application of science and math to solve real-world problems. "
                "There are many branches: mechanical, electrical, civil, software, and more!"
            )
        elif "python" in msg:
            return (
                "Python is a high-level, interpreted language known for its readability and vast ecosystem. "
                "Great for web development, data science, automation, and more."
            )
        elif "ai" in msg or "artificial intelligence" in msg:
            return (
                "AI stands for Artificial Intelligence. It refers to machines or software mimicking human intelligence—"
                "like learning, reasoning, problem-solving, and understanding language!"
            )
        elif "hello" in msg or "hi" in msg:
            return "Hey there! 👋 How can I assist you today?"
        elif "time" in msg:
            return f"The current time is {datetime.now().strftime('%H:%M:%S')}."
        elif "joke" in msg:
            return "Why do programmers prefer dark mode? Because light attracts bugs. 😄"
        else:
            return (
                "That's interesting! I'm still learning, but I'd love to help. "
                "Try asking me about whales, C++, Python, engineering, AI, or even a joke!"
            )

    bot_response = generate_response(user_message)
    return jsonify({'response': bot_response})

if __name__ == '__main__':
    app.run(debug=True)
