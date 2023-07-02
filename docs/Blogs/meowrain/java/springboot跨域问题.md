![image](https://github.com/meowrain/doc-for-sxau/assets/107172084/668e391f-b84b-45cf-a333-2dca93d561ee)
```java
package com.kob.backend.controller.pk;

import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RestController;

import java.util.HashMap;
import java.util.Map;

@RestController
@RequestMapping("/pk/")
public class BotInfoController {
    @RequestMapping("getbotinfo")
    public Map<String,String> getBotInfo(){
        Map<String,String> bot1 = new HashMap<>();
        bot1.put("name","meowrain");
        bot1.put("rating","1500");
        return bot1;
    }
}

```
如上
