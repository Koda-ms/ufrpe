package questao04.negocio.beans;

public enum CategoriaProduto {
	VESTUARIO(0), ELETRONICOS(1), UTENSILIOS_DOMESTICOS(2), FERRAMENTAS(3);

	private int secao;
	
	CategoriaProduto(int secao) {
		this.secao = secao;
	}
	
	public int getSecao() {
		return secao;
	}
}
