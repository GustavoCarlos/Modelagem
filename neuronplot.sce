
clear()
clf

M = fscanfMat("neuronData.txt")

X = M(:,1)
Y = M(:,2)

//subplot(2,1,1)
//plot([V, H1])
//plot([1:201],V,[1:201],H1)
//title("Vegetação e Herbivoro 1", "fontsize", 4)
//legend("Vegetação", "Herbivoro 1")
//xlabel("Tempo(t)", "fontsize",2)
//ylabel("População","fontsize", 2,"color", "blue")

//subplot(2,1,2)
plot(X)
//plot([H1,H2, C1,C2])
//title("Grafico de comportamento das populações","fontsize", 4, "color", "blue")
//legend("Fitoplãncton", "Camarão", "Peixe", "Homem", "Urso")
//legend("Herbivoro 1", "Herbivoro 2", "Carnivoro 1", "Carnivoro 2")
xlabel("Tempo(t)","fontsize",2)
ylabel("Voltage(V)", "fontsize", 2)
