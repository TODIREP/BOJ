import java.util.*
class Solution {
    fun solution(s: String): IntArray {
        val arr = arrayListOf<IntArray>()
        s.substring(2, s.length - 2).split("},{").toList().forEach {
            arr.add(it.split(",").map(String::toInt).toIntArray())
        }
        arr.sortBy { it.size }
        val size = arr.size
        val tuple = TreeMap<Int, Int>()
        arr[size - 1].forEach {
            tuple[it] = tuple.getOrDefault(it, 0) + 1
        }
        var answer = arrayListOf<Int>()
        arr.forEach { a -> 
            a.forEach { item -> 
                val value = tuple.get(item)!!
                if (value > 0) {
                    tuple[item] = value - 1
                    answer.add(item)
                }
            }
        }
        return answer.toIntArray()
    }
}