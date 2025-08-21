## **Quick refresher: CAP Theorem**

CAP theorem (Eric Brewer) bolta hai ki **distributed systems** mein aap ek hi time par teenon guarantees **perfectly** nahi de sakte:

1. **Consistency (C):** Har node par same data mile instantly.
2. **Availability (A):** System hamesha response de (even if outdated).
3. **Partition Tolerance (P):** System network failures (nodes ke beech communication tootna) ke bawajood kaam kare.

A distributed system **must tolerate partitions (P)** because real-world networks fail. So **you must choose between C vs A during a partition.**

---

## **Partition Tolerance (P) kya hai?**

* **Meaning:** Agar network ke nodes ke beech link toot gaya ya packets drop ho rahe hain, system phir bhi kuch na kuch service deta rahe.
* System **fail nahi hona chahiye** sirf isliye kyunki kuch nodes ek dusre tak nahi pahunch pa rahe.
* Practically: Aapko assume karna hi padta hai ki network unreliable hai → *partitions will happen!*

---

### **Real-life analogy (Hinglish)**

* Socho tumhare doston ka WhatsApp group hai (distributed system).
* Ek dost ki internet band ho gayi (network partition).
* **Partition tolerance** ka matlab hai: baaki log to group me baat karte rahenge, chat band nahi hogi, bhale hi us dost ko messages late milen.

---

## **What happens when P occurs?**

* Jab partition hota hai, aap **ya to consistency todte ho ya availability**:

  * **CP system (Consistency + Partition tolerance):**

    * System correct data dene ke liye kuch requests ko reject karega → *availability sacrifice*.
    * Example: **MongoDB in “majority write concern” mode** or **Zookeeper**.
  * **AP system (Availability + Partition tolerance):**

    * System hamesha response dega, chahe outdated ya inconsistent ho → *consistency sacrifice*.
    * Example: **Cassandra**, **DynamoDB**.

---

### **Key points about P**

* You **cannot avoid** partition tolerance in distributed systems — you *have to* design for it.
* The real decision is **C vs A when P happens**.
* Cloud-scale databases are always **CP** or **AP**, never "just CA".
