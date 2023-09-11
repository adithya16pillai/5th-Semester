public class NibbleSwap {
    public static byte swapNibbles(byte b) {
        // Extract the upper and lower nibbles
        byte upperNibble = (byte) ((b & 0xF0) >>> 4);
        byte lowerNibble = (byte) (b & 0x0F);
        // Shift the nibbles and combine them
        byte swappedByte = (byte) ((lowerNibble << 4) | upperNibble);
        return swappedByte;
    }
    public static void main(String[] args) {
        byte byteValue = (byte) 0xAB; // 1010 1011 in binary
        byte swappedByte = swapNibbles(byteValue);
        System.out.println("Original byte: " + Integer.toBinaryString(byteValue & 0xFF));
        System.out.println("Swapped byte: " + Integer.toBinaryString(swappedByte & 0xFF));
    }
}