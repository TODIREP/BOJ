class Solution {
    fun solution(numbers: IntArray): String {
        if (numbers.sum() == 0) return "0"
        return numbers.sortedWith(Comparator { a: Int, b: Int ->
            "${b}${a}".toInt() - "${a}${b}".toInt()
        }).joinToString(separator = "")
    }
}