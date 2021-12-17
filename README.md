# Truecaller-search-optimization
Data Structures

<img align="left" alt="Visual Studio Code" width="820px" src="https://www.businessinsider.in/thumb/msid-73934849,width-600,resizemode-4,imgsize-158495/tech/apps/news/truecallers-has-three-fourths-of-its-customers-in-india-all-thanks-to-endless-spam-calls/truecaller-stock2.jpg" />
<hr>
# About

---

Truecaller is the leading global platform for verifying contacts and blocking unwanted communication. Truecaller is an essential part of everyday communication for around 300 million active users, with half a billion downloads since launch.
<br/>
Truecaller is a smartphone application that has features of caller-identification, call-blocking, flash-messaging, call-recording, Chat & Voice by using the internet. It requires users to provide a standard cellular mobile number for registering with the service. The app is available for Android and iOS.

# Need

---

With Truecaller we are making your dialling experience smarter and easier to use. By using Truecaller as your default dialer you'll be able to quickly and easily access all your existing contacts, see more relevant information about them and also identify unknown numbers and block unwanted callers.

<img align="left" alt="Visual Studio Code" width="820px" src="https://i.pinimg.com/originals/91/4c/68/914c68404b174a44bf870ab18f92cef9.jpg" />

# Trie Datastructure

---

A Trie is an advanced data structure that is sometimes also known as prefix tree or digital tree. It is a tree that stores the data in an ordered and efficient way. We generally use trie's to store strings. Each node of a trie can have as many as 26 references (pointers).

<img align="left" alt="Visual Studio Code" width="820px" height="500px" src="https://github.com/harshithvh/Truecaller-search-optimization/blob/main/img/img1.png" />

# Trie - Insertion

---

Insertion proceeds by walking the Trie according to the string to be inserted, then appending new nodes for the suffix of the string that is not contained in the Trie.

<img align="left" alt="Visual Studio Code" width="820px" height="400px" src="https://github.com/harshithvh/Truecaller-search-optimization/blob/main/img/img2.png" />

# Trie - Search

---

Searching proceeds the similar way by walking the Trie according to the string to be searched, returning false if the string is not found. 

<img align="left" alt="Visual Studio Code" width="820px" height="400px" src="https://github.com/harshithvh/Truecaller-search-optimization/blob/main/img/img3.png" />

# Trie - Complexity

---

The height (number of levels present) of this trie will always be 10. So, to search a contact, the algorithm will at most have to compare data 10 times.

<img align="left" alt="Visual Studio Code" width="820px" height="400px" src="https://github.com/harshithvh/Truecaller-search-optimization/blob/main/img/img4.png" />

# Trie - Suggestion

---

By using tries, we can also offer suggestions to user. Suppose, user dialed ‘9223’, then we will traverse the trie till last dialed digit, and from that node, we will return all leaf nodes.

<img align="left" alt="Visual Studio Code" width="820px" height="400px" src="https://github.com/harshithvh/Truecaller-search-optimization/blob/main/img/img5.png" />
