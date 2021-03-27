import java.io.BufferedReader
import java.io.BufferedWriter
import java.io.InputStreamReader
import java.io.OutputStreamWriter

fun lowerBound(target: MutableList<Int>, size: Int, num: Int): Int {
    var l = 0
    var r = size
    while (l < r) {
        val m = (l + r) / 2
        if (target[m] >= num) r = m
        else l = m + 1
    }
    return l
}
fun upperBound(target: MutableList<Int>, size: Int, num: Int): Int {
    var l = 0
    var r = size
    while (l < r) {
        val m = (l + r) / 2
        if (target[m] > num) r = m
        else l = m + 1
    }
    return l
}
fun getPrefix(target: IntArray, size: Int, pizza: Int): MutableList<Int> {
    val res = mutableListOf<Int>()
    var l = 0
    var r = 0
    var sum = 0
    res.add(0)
    while (l < size) {
        sum += target[r++]
        when (sum <= pizza) {
            true -> res.add(sum)
            else -> {
                l++
                r = l
                sum = 0
            }
        }
        if (r == size) r = 0
        if (((l == 0) and (r == 0)) or ((r + 1) == l)) {
            l++
            r = l
            sum = 0
        }
    }
    res.sort()
    return res
}
fun solution() = with(BufferedReader(InputStreamReader(System.`in`))) {
    val bufferedWriter = BufferedWriter(OutputStreamWriter(System.out))
    fun inputList(size: Int): IntArray {
        val res = IntArray(size)
        for (index in 0 until size) {
            res[index] = readLine().toInt()
        }
        return res
    }
    val total = readLine().toInt()
    val (m, n) = readLine().split(" ").map { it.toInt() }
    val pizzaA = inputList(m)
    val pizzaB = inputList(n)

    val prefixA = getPrefix(pizzaA, m, total)
    val prefixB = getPrefix(pizzaB, n, total)

    var result: Long = 0
    val prefixBLen = prefixB.size
    for (sum in prefixA) {
        val check = total - sum
        val upper = upperBound(prefixB, prefixBLen, check)
        val lower = lowerBound(prefixB, prefixBLen, check)
        if (lower < prefixBLen) {
            if (prefixB[lower] == check) {
                result += (upper.toLong() - lower.toLong())
            }
        }
    }
    bufferedWriter.write("$result")
    bufferedWriter.close()
}
fun main() {
    solution()
}