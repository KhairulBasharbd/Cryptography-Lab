import java.math.BigInteger;
import java.util.ArrayList;
import java.util.Scanner;

public class RSACipher {

    // Function to calculate GCD
    public static long gcd(long a, long b) {
        if (b == 0) return a;
        return gcd(b, a % b);
    }

    // Function for modular exponentiation
    public static long powerMod(long base, long exp, long mod) {
        long result = 1;
        while (exp > 0) {
            if (exp % 2 == 1) result = (result * base) % mod;
            base = (base * base) % mod;
            exp /= 2;
        }
        return result;
    }

    // Function to split the message into chunks
    public static ArrayList<Long> splitMessage(String message, int chunkSize) {
        ArrayList<Long> chunks = new ArrayList<>();
        for (int i = 0; i < message.length(); i += chunkSize) {
            String chunk = message.substring(i, Math.min(i + chunkSize, message.length()));
            chunks.add(Long.parseLong(chunk)); // Convert string chunk to long
        }
        return chunks;
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        // Taking inputs for e, d, n, and message
        System.out.print("Enter public key exponent (e): ");
        long e = scanner.nextLong(); // e
        
        System.out.print("Enter private key (d): ");
        long d = scanner.nextLong(); // d
        
        System.out.print("Enter modulus (n): ");
        long n = scanner.nextLong(); // n
        
        System.out.print("Enter plaintext message (m): ");
        String message = scanner.next(); // Message to encrypt
        
        // Split the message into chunks of size 3
        ArrayList<Long> chunks = splitMessage(message, 3);
        
        // Encryption
        StringBuilder encryptedString = new StringBuilder();
        for (long chunk : chunks) {
            long encrypted = powerMod(chunk, e, n);
            encryptedString.append(encrypted).append(" "); // Append encrypted chunk to string
        }

        System.out.println("Concatenated Encrypted String: " + encryptedString.toString().trim());

        // Decryption
        StringBuilder decryptedString = new StringBuilder();
        String[] encryptedChunks = encryptedString.toString().trim().split(" ");
        
        for (String token : encryptedChunks) {
            long encryptedChunk = Long.parseLong(token);
            long decrypted = powerMod(encryptedChunk, d, n);
            decryptedString.append(decrypted); // Append decrypted chunk to string
        }

        System.out.println("Concatenated Decrypted String: " + decryptedString.toString());

        scanner.close();
    }
}
