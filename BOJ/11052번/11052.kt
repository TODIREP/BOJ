fun main() {
    val br = System.`in`.bufferedReader()
    val bw = System.out.bufferedWriter()
    val n = br.readLine().toInt()
    val price = br.readLine().split(" ").map(String::toInt).toIntArray()
    val answer = price.copyOf()
    for (a in 0 until n) {
        for (b in a until n) {
            if (a + b + 1 < n) answer[a + b + 1] = answer[a + b + 1].coerceAtLeast(answer[a] + answer[b])
        }
    }
    bw.write("${answer[n - 1]}")
    bw.close()
}