import java.util.*
import kotlin.math.*
fun main() {
    val br = System.`in`.bufferedReader()
    val bw = System.out.bufferedWriter()
    val n = br.readLine().toInt()
    val words = mutableListOf<String>()
    val word = IntArray(26) { 0 }
    val queue: Queue<Int> = LinkedList()
    intArrayOf(9, 8, 7, 6, 5, 4, 3, 2, 1, 0).forEach { queue.add(it) }
    repeat(n) {
        val input = br.readLine()
        val size = input.length
        words.add(input)
        var index = 10.0.pow(size - 1).toInt()
        repeat(size) {
            word[input[it] - 'A'] += index
            index /= 10
        }
    }
    val list = mutableListOf<Pair<Int, Int>>()
    repeat(26) { if (word[it] > 0) list.add(Pair(it, word[it])) }
    list.sortedByDescending { it.second }.forEach { word[it.first] = queue.remove() }
    var result: Long = 0
    repeat(n) {
        val number = StringBuilder()
        val size = words[it].length
        repeat(size) { index -> number.append(word[words[it][index] - 'A']) }
        val num: Long = number.toString().toLong()
        result += num
    }
    bw.write("$result")
    bw.close()
}