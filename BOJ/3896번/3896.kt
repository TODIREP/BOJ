import java.io.BufferedReader
import java.io.BufferedWriter
import java.io.InputStreamReader
import java.io.OutputStreamWriter

fun solution() = with(BufferedReader(InputStreamReader(System.`in`))) {
    val bufferedWriter = BufferedWriter(OutputStreamWriter(System.out))

    val limit = 2000000
    val isSosu = BooleanArray(limit + 1)
    val sosu = mutableListOf<Int>()

    for (num in 2 until limit) {
        if (!isSosu[num]) {
            sosu.add(num)
            var index = 2
            while (index * num <= limit) {
                isSosu[index * num] = true
                index++
            }
        }
    }

    fun binarySearch(num: Int): Int {
        var l = 0
        var r = sosu.size

        while (l < r) {
            val m = (l + r) / 2
            if (sosu[m] > num) r = m
            else l = m + 1
        }
        return l
    }

    val t = readLine().toInt()
    repeat(t) {
        val target = readLine().toInt()
        bufferedWriter.write("${when (isSosu[target]) {
            false -> 0
            else -> {
                val left = binarySearch(target)
                when (sosu[left] > target) {
                    true -> sosu[left] - sosu[left - 1]
                    else -> sosu[left + 1] - sosu[left]
                }
            }
        }}\n")
    }
    bufferedWriter.close()
}
fun main() {
    solution()
}