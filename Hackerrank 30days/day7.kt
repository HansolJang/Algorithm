import java.io.*
import java.math.*
import java.security.*
import java.text.*
import java.util.*
import java.util.concurrent.*
import java.util.function.*
import java.util.regex.*
import java.util.stream.*
import kotlin.collections.*
import kotlin.comparisons.*
import kotlin.io.*
import kotlin.jvm.*
import kotlin.jvm.functions.*
import kotlin.jvm.internal.*
import kotlin.ranges.*
import kotlin.sequences.*
import kotlin.text.*



fun main(args: Array<String>) {
    val scan = Scanner(System.`in`)

    val n = scan.nextLine().trim().toInt()
    val map = HashMap<String, String>()

    for(i in 0..n-1) {
        val splitarr = scan.nextLine().split(" ")
        map.set(splitarr.get(0), splitarr.get(1))
    }

    for(i in 0..n-1) {
        val input = scan.nextLine()
        if(map.get(input) != null) {
            println("${input}=${map.get(input)}")
        } else {
            println("Not found")
        }      
    }
}
