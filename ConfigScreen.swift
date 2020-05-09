//
//  ConfigScreen.swift
//  642project
//
//  Created by Malkam on 4/5/20.
//  Copyright © 2020 Malkam. All rights reserved.
//

//import Foundation
//
//  ViewController.swift
//  642project
//
//  Created by Malkam on 4/5/20.
//  Copyright © 2020 Malkam. All rights reserved.
//

import UIKit

    class ConfigScreen: UIViewController,UIPickerViewDelegate, UIPickerViewDataSource {
    
        var arrayInt = [1,2,3,4,5,6,7,8,
                        9,10,11,12,13,14,
                        15,16,17,18,19,20,
                        21,22,23,24,25,26,
                        27,28,29,30,31,32,
                        33,34,35,36,37,38,
                        39,40,41,42,43,44,
                        45,46,47,48]
        
        let arrayString = ["1 U","2 U","3 U","4 U","5 U","6 U","7 U","8 U","9 U","10 U","11 U","12 U","13 U","14 U","15 U","16 U","17 U","18 U","19 U","20 U","21 U","22 U","23 U","24 U","25 U","26 U","27 U","28 U","29 U","30 U","31 U","32 U","33 U","34 U","35 U","36 U","37 U","38 U","39 U","40 U","41 U","42 U","43 U","44 U","45 U","46 U","47 U"]
        
        let arrayStrings = ["0 U","1","2","3","4","5","6","7","8",
                           "9","10","11","12","13","14","15","16",
                           "17","18","19","20","21","22","23","24",
                           "25","26","27","28","29","30","31","32",
                           "33","34","35","36","37","38","39","40",
                           "41","42","43","44","45","46","47","48"]
        
        struct MyVariables {
            static var UP = ""
            static var CURRENT = "0 U"
            static var arrayCurrent = [String]()
            static var DOWN = ""
            static var INT = 0
        }
        
        //@IBOutlet weak var curPos: UILabel!
        @IBOutlet weak var pickerView: UIPickerView!
        @IBOutlet weak var newPos: UILabel!
        
        let UP = MyVariables.UP
        let CURRENT = MyVariables.CURRENT
        let DOWN = MyVariables.DOWN
        let arrayCurrent = MyVariables.arrayCurrent
        let INT = MyVariables.INT
        
        @IBAction func btnUp(_ sender: UIButton) {
             if INT > 0 && INT < 49{
                MyVariables.UP = arrayCurrent[INT + 1]
                newPos.text = "New Position :  " + UP
            }
        }
        @IBAction func btnDown(_ sender: UIButton) {
            if INT > 0 && INT < 49{
                MyVariables.DOWN = arrayCurrent[INT - 1]
                newPos.text = "New Position :  " + DOWN
            }
        }
        
        @IBAction func stop(_ sender: UIButton) {
            //curPos.text = "Current Position :  " + "STOP"
            newPos.text = "New Position :  " + "STOP"
        }
        
        @IBAction func btnReset(_ sender: UIButton) {
            newPos.text = "New Position :  " + "0" + "U"
        }
        
        override func viewDidLoad() {
            super.viewDidLoad()
            
            pickerView.delegate = self
            pickerView.dataSource = self
        }
        
        func numberOfComponents(in pickerView: UIPickerView) -> Int {
            return 1
        }
        
        func pickerView(_ pickerView: UIPickerView, numberOfRowsInComponent component: Int) -> Int {
            return arrayString.count
        }
        
        func pickerView(_ pickerView: UIPickerView, titleForRow row: Int, forComponent component: Int) -> String? {
            return arrayString[row]
        }
        
        func pickerView(_ pickerView: UIPickerView, didSelectRow row: Int, inComponent component: Int){
            //var curPosInt = 0
            MyVariables.arrayCurrent = arrayString
            let itemSelected = arrayString[row]
            MyVariables.CURRENT = itemSelected
            newPos.text = "New Position : " + itemSelected + "U"

            
//                for n in curPosInt...row{
//                    let intSelected = arrayString[n]
//                    curPos.text = "Current Position" + intSelected
//                    curPosInt += 1
//                }
        }
        
//        @IBAction func btnUp(_ sender: Any) {
//            arrayString[3]
//            curPos.text = "New Position :  " + itemSelected
//        }

}
