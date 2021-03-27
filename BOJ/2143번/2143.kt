import java.io.BufferedReader
import java.io.BufferedWriter
import java.io.InputStreamReader
import java.io.OutputStreamWriter
import java.util.*

fun lowerBound(target: MutableList<Int>, left: Int, right: Int, num: Int): Int {
    var l = left
    var r = right
    while (l < r) {
        val m = (l + r) / 2
        if (target[m] >= num) r = m
        else l = m + 1
    }
    return l
}
fun upperBound(target: MutableList<Int>, left: Int, right: Int, num: Int): Int {
    var l = left
    var r = right
    while (l < r) {
        val m = (l + r) / 2
        if (target[m] > num) r = m
        else l = m + 1
    }
    return l
}
fun getPrefix(target: MutableList<Int>, size: Int): IntArray {
    val prefix = IntArray(size) { target[0] }
    for (index in 1 until size) {
        prefix[index] = prefix[index - 1] + target[index]
    }
    return prefix
}
fun getSubSum(target: IntArray, size: Int): MutableList<Int> {
    val subSum: MutableList<Int> = mutableListOf()
    for (index in 0 until size) {
        subSum.add(target[index])
        for (prev in index - 1 downTo 0) {
            val prevSum = target[index] - target[prev]
            subSum.add(prevSum)
        }
    }
    subSum.sort()
    return subSum
}
fun solution() = with(BufferedReader(InputStreamReader(System.`in`))) {
    val bufferedWriter = BufferedWriter(OutputStreamWriter(System.out))
    fun inputList(size: Int): MutableList<Int> {
        val input = MutableList(size) { 0 }
        val token = StringTokenizer(readLine())
        for (index in 0 until size) {
            input[index] = token.nextToken().toInt()
        }
        return input
    }

    val t = readLine().toInt()
    val a = readLine().toInt()
    val arrayA: MutableList<Int> = inputList(a)
    val b = readLine().toInt()
    val arrayB: MutableList<Int> = inputList(b)

    val prefixA = getPrefix(arrayA, a)
    val prefixB = getPrefix(arrayB, b)

    val targetA: MutableList<Int> = getSubSum(prefixA, a)
    val targetB: MutableList<Int> = getSubSum(prefixB, b)

    val targetBLen = targetB.size
    var result: Long = 0
    for (sum in targetA) {
        val check = t - sum
        val upper = upperBound(targetB, 0, targetBLen, check)
        val lower = lowerBound(targetB, 0, targetBLen, check)

        if (lower < targetBLen) {
            if (targetB[lower] == check) {
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