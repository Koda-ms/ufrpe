package questao03;

import java.time.LocalDateTime;

public interface ITransacao {

	LocalDateTime getData();

	String getTipo();

	String getDescricao();

	double calcularTotal();

}
