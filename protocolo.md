# Protocolo de comunicação com os robôs

## Computador -> Chicó

Byte | Função              
-----|---------------------
  1  | Endereço (3 bits)   
  "  | Comando  (5 bits)   
  2  | Velocidade x        
  3  | Velocidade y        
  4  | Velocidade angular  
  5  | Ângulo do chute  (6 bits)
  "  | Potência (2 bits)   

## Chicó -> computador

Byte | Função              
-----|---------------------
  1  | Endereço (3 bits)   
  "  | Comando  (5 bits)   
  2  | Status da bateria        
  3  | Presença da bola        


precisamos fazer um CRC nosso, fikcou decidido em reunião 
que  nosso CRC é uma redundânmocia  necessária 