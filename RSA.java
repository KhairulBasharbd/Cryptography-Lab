import java.math.BigInteger;
import java.util.Scanner;

public class RSA {
    public static BigInteger gcd(BigInteger a, BigInteger b) {
        return b.equals(BigInteger.ZERO) ? a : gcd(b, a.mod(b));
    }

    public static BigInteger modInverse(BigInteger e, BigInteger phi) {
        return e.modInverse(phi);
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        
        // Initialize prime numbers p and q
        BigInteger p = new BigInteger("61");
        BigInteger q = new BigInteger("53");
        
        // Compute n = p * q
        BigInteger n = p.multiply(q);
        
        // Compute phi(n) = (p-1) * (q-1)
        BigInteger phi = p.subtract(BigInteger.ONE).multiply(q.subtract(BigInteger.ONE));

        // Choose a small odd integer e that is relatively prime to phi
        BigInteger e = new BigInteger("17");
        while (!gcd(e, phi).equals(BigInteger.ONE)) {
            e = e.add(BigInteger.ONE);
        }

        // Compute d such that (e * d) ≡ 1 (mod phi)
        BigInteger d = modInverse(e, phi);

        System.out.println("Public Key (e, n) = (" + e + ", " + n + ")");
        System.out.println("Private Key (d, n) = (" + d + ", " + n + ")");

        // Read input plaintext
        System.out.print("Enter plaintext: ");
        String plaintext = sc.nextLine();
        
        // Convert plaintext into byte array
        byte[] bytes = plaintext.getBytes();

        // Encrypt the byte array
        BigInteger message = new BigInteger(1, bytes); // 1 for positive BigInteger
        if (message.compareTo(n) >= 0) {
            throw new IllegalArgumentException("Message too large to encrypt.");
        }

        BigInteger encrypted = message.modPow(e, n);

        // Decrypt the message
        BigInteger decrypted = encrypted.modPow(d, n);
        byte[] decryptedBytes = decrypted.toByteArray();
        String decryptedMessage = new String(decryptedBytes);

        // Output results
        System.out.println("Encrypted Message: " + encrypted);
        System.out.println("Decrypted Message: " + decryptedMessage);

        sc.close();
    }
}
