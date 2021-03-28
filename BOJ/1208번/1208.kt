import java.io.BufferedReader
import java.io.BufferedWriter
import java.io.InputStreamReader
import java.io.OutputStreamWriter
import java.util.*

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
fun solution() = with(BufferedReader(InputStreamReader(System.`in`))) {
    val bufferedWriter = BufferedWriter(OutputStreamWriter(System.out))
    fun inputList(token: StringTokenizer, size: Int): MutableList<Int> {
        val array = mutableListOf<Int>()
        for (i in 0 until size) {
            array.add(token.nextToken().toInt())
        }
        return array
    }
    val (n, s) = readLine().split(" ").map { it.toInt() }
    val token = StringTokenizer(readLine())
    val center = n / 2
    val leftArray = inputList(token, center)
    val rightArray = inputList(token, n - center)
    var result: Long = 0
    fun getSubSum(target: MutableList<Int>, size: Int): MutableList<Int> {
        val array = mutableListOf<Int>()
        fun search(index: Int, sum: Int, count: Int) {
            if (index == size) {
                if (count > 0) {
                    if (sum == s) result += 1L
                    array.add(sum)
                }
                return
            }
            search(index + 1, sum, count)
            search(index + 1, sum + target[index], count + 1)
        }
        search(0, 0, 0)
        array.sort()
        return array
    }
    val leftSum = getSubSum(leftArray, center)
    val rightSum = getSubSum(rightArray, n - center)
    val rightSize = rightSum.size
    for (lSum in leftSum) {
        val check = s - lSum
        val upper = upperBound(rightSum, rightSize, check)
        val lower = lowerBound(rightSum, rightSize, check)
        if (lower < rightSize) {
            if (rightSum[lower] == check) {
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