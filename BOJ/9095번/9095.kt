fun main() {
    val br = System.`in`.bufferedReader()
    val bw = System.out.bufferedWriter()
    val answer = IntArray(11) { 0 }
    answer[0] = 1
    repeat(11) {
        if (it + 1 < 11) answer[it + 1] += answer[it]
        if (it + 2 < 11) answer[it + 2] += answer[it]
        if (it + 3 < 11) answer[it + 3] += answer[it]
    }
    answer[0] = 0
    val n = br.readLine().toInt()
    repeat(n) { bw.write("${answer[br.readLine().toInt()]}\n") }
    bw.close()
}