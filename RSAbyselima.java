import java.math.BigInteger;
import java.security.SecureRandom;
import java.util.Arrays;
import java.util.Random;
import java.util.Scanner;

import static java.math.BigInteger.ONE;

public class RSAbyselima {

    public byte[] doEncryption(String M, BigInteger e, BigInteger n) {
        // First turns M into a number m smaller than n
        BigInteger m = new BigInteger(M.getBytes());

        // Check if message size is larger than n
        if (m.compareTo(n) >= 0) {
            throw new IllegalArgumentException("Message too large to encrypt!");
        }

        // Compute the ciphertext c = m^e mod n
        byte[] c = m.modPow(e, n).toByteArray();
        String x = Arrays.toString(c);
        System.out.println("Encrypted Ciphertext: " + x);
        return c;
    }

    public String doDecryption(BigInteger d, BigInteger n, byte[] c) {
        BigInteger decrypted_m = new BigInteger(c).modPow(d, n);
        String decrypted_M = new String(decrypted_m.toByteArray());
        return decrypted_M;
    }

    public static void main(String[] args) {
        // 1. Choosing two random prime numbers
        int bitLength = 128; // random numbers bitLength
        Random rnd = new SecureRandom();
        BigInteger p = BigInteger.probablePrime(bitLength, rnd);
        BigInteger q = BigInteger.probablePrime(bitLength, rnd);

        // 2. Calculating n = p * q
        BigInteger n = p.multiply(q);

        // 3. Calculate phi = (p - 1) * (q - 1)
        BigInteger phi = (p.subtract(ONE)).multiply(q.subtract(ONE));

        // 4. Calculating e such that e is coprime to phi
        BigInteger e = BigInteger.valueOf(65537); // Common choice for e
        // Ensure e is coprime with phi
        if (!e.gcd(phi).equals(ONE)) {
            throw new IllegalArgumentException("Chosen 'e' is not coprime with phi");
        }

        // 5. Compute d such that (e * d) mod phi == 1
        BigInteger d = e.modInverse(phi);

        System.out.println("Public Key = (" + e + "," + n + ")");
        System.out.println("Private Key = (" + d + "," + n + ")");

        // Input message
        RSAbyselima rsaObj = new RSAbyselima();

        Scanner sc = new Scanner(System.in);
        System.out.print("Enter a string to encrypt: ");
        String M = sc.nextLine();

        // Encrypting a message
        byte[] c = rsaObj.doEncryption(M, e, n);

        // Decrypting a message
        String decryptedMsg = rsaObj.doDecryption(d, n, c);
        System.out.println("Decrypted Message: " + decryptedMsg);

        sc.close();
    }
}
