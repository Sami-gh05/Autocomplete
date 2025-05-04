# 🔍 Autocomplete System

A fast and efficient autocomplete system implemented in C++ using a Trie data structure! 🚀

## ✨ Features

- ⚡ Lightning-fast word suggestions
- 📊 Frequency-based word ranking
- 🔄 Dynamic word insertion and updating
- 🎯 Top 5 most relevant suggestions
- 📝 Case-insensitive word handling

## 🛠️ Implementation Details

The system uses a Trie data structure with the following key components:

- `TrieNode` class for storing characters and word suggestions
- Frequency-based word ranking system
- Efficient word insertion and retrieval
- Smart suggestion sorting based on frequency and alphabetical order

## 📋 Usage

1. Compile the program:
```bash
g++ Autocomplete.cpp -o autocomplete
```

2. Run the program:
```bash
./autocomplete
```

3. Input format:
```
n
query word [count]
```

Where:
- `n` is the number of operations
- `query` can be either "insert" or "suggest"
- `word` is the word to insert or get suggestions for
- `count` is the frequency count (only for insert operations)

## 📝 Example

Input:
```
3
insert hello 5
insert helloworld 3
suggest hell
```

Output:
```
hello
helloworld
```

## 🏗️ Project Structure

- `Autocomplete.cpp` - Main implementation file containing the Trie-based autocomplete system

## 🤝 Contributing

Feel free to submit issues and enhancement requests! Pull requests are welcome.

