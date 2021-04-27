fun main() {
    val br = System.`in`.bufferedReader()
    val bw = System.out.bufferedWriter()
    val (n, s) = br.readLine().split(" ").map(String::toInt)
    val array = br.readLine().split(" ").map(String::toInt).toIntArray()
    val limit = (1 shl n)
    var answer = 0
    for (it in 1 until limit) {
        var sum = 0
        for (index in 0 until n) {
            val check = (1 shl index)
            if (it and check == check) sum += array[index]
        }
        if (sum == s) answer++
    }
    bw.write("$answer")
    bw.close()
}