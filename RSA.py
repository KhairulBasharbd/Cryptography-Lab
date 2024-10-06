import sys
sys.stdin=open('rsa.txt',"r")

def rsa_encrypt(message, e, n):
    ciphertext = pow(message, e, n)
    return ciphertext

def rsa_decrypt(ciphertext, d, n):
    decrypted_message = pow(ciphertext, d, n)
    return decrypted_message

def split_message(message, chunk_size):
    message_str = str(message)
    chunks = []
    for i in range(0, len(message_str), chunk_size):
        chunk = int(message_str[i:i + chunk_size])
        chunks.append(chunk)
    return chunks
e=int(input())
# e = 79    
d = int(input()) #1019   
n = int(input()) #3337       
message = input() #6882326879666683

chunk_size = len(str(n))
chunks = split_message(message, chunk_size-1)

encrypted_string=""
for chunk in chunks:
    encrypted_string+=(str)(rsa_encrypt(chunk,e,n))


print("Concatenated Encrypted String:", encrypted_string)

## for decryption

chunks = split_message(encrypted_string, chunk_size)
decrypted_string=""
for chunk in chunks:
    decrypted_string+=(str)(rsa_decrypt(chunk,d,n))

print("Concatenated Decrypted String:", decrypted_string)