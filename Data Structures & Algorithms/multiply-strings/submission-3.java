class Solution {
    public String multiply(String num1, String num2) {
        if (num1.equals("0") || num2.equals("0")) return "0";

        int n = num1.length();
        int m = num2.length();
        int[] result = new int[n + m];

        for (int i = m - 1; i >= 0; i--) {
            int x = num2.charAt(i) - '0';
            for (int j = n - 1; j >= 0; j--) {
                int y = num1.charAt(j) - '0';
                int mul = x * y;
                int sum = result[i + j + 1] + mul;

                result[i + j + 1] = sum % 10;
                result[i + j] += sum / 10;
            }
        }

        // Build the result string
        StringBuilder ans = new StringBuilder();
        int i = 0;
        // Skip leading zeros
        while (i < result.length && result[i] == 0) i++;
        while (i < result.length) {
            ans.append(result[i]);
            i++;
        }

        // If the result is empty (all zeros)
        if (ans.length() == 0) return "0";
        return ans.toString();
    }
}
